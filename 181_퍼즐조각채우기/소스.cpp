#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방문한 게임 보드의 행렬
bool visit[51][51];

//  방향 상하좌우에 대한 배열 
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

vector<pair<int,int>> BFS(vector<vector<int>>& gb, int blockVlaue, int i, int j)
{
    // 방문 체크 및 BFS로 (이어져있는 블록 가져오기) (비어있는 블록 가져오기)
    visit[i][j] = true;

    vector<pair<int, int>> vp;
    queue<pair<int, int>> qp;

    qp.push(make_pair(i, j));
    vp.push_back(make_pair(i, j));

    while (qp.empty() == false)
    {
        int y = qp.front().first;
        int x = qp.front().second;
        qp.pop();

        // 상하좌우 블록 값 체크 하기 
        for (int i = 0; i < 4; i++)
        {
            int temp_y = y + dy[i];
            int temp_x = x + dx[i];

            // BFS 범위 벗어나는 경우 
            if (temp_y <0 || temp_x<0 || temp_x >= gb.size() || temp_y >= gb.size())
            {
                continue;
            }

            // 방문한 적이 있거나 블록에 대한 값이 다른 경우 !
            if (visit[temp_y][temp_x] || gb[temp_y][temp_x] != blockVlaue)
            {
                continue;
            }

            visit[temp_y][temp_x] = true;
            qp.push(make_pair(temp_y, temp_x));
            vp.push_back(make_pair(temp_y, temp_x));
        }
    }
    return vp;
}

vector<pair<int, int>> ConvertPosZero(vector<pair<int, int>> vp_block, int len)
{
    int j_min = len;
    int i_min = len;

    // 블럭에서 제일 작은 좌표를 찾는다.
    for (int i = 0; i < vp_block.size(); i++)
    {
        j_min = j_min > vp_block[i].second ? vp_block[i].second : j_min;
        i_min = i_min > vp_block[i].first ? vp_block[i].first : i_min;
    }

    // 제일 작은 좌표만큼 모든 좌표에서 빼주고 0으로 위치를 변경한다.
    for (int i = 0; i < vp_block.size(); i++)
    {
        vp_block[i].first -= i_min;
        vp_block[i].second -= j_min;
    }

    return vp_block;
}

// 90 도 회전 !
void rotation(vector<pair<int, int>>& rTable)
{
    int row = 0;
    
    for (int i = 0; i < rTable.size(); i++)
    {
        row = row < rTable[i].first ? rTable[i].first : row;
    }

    for (int i = 0; i < rTable.size(); i++)
    {
        int y = rTable[i].first;
        int x = rTable[i].second;
        rTable[i].first = x;
        rTable[i].second = row - y;
    }
}


int Board_Table_Matching(vector<vector<pair<int, int>>> &board, vector<vector<pair<int, int>>> &table)
{
    int answer = 0;
    vector<bool> table_visit(table.size(), false);

    for (vector<pair<int, int>> vp : board)
    {
        for (int i = 0; i < table.size(); i++)
        {
            //이미 사용을 완료한 퍼즐인경우 리턴 
            if (table_visit[i] == true)
            {
                continue;
            }

            vector<pair<int, int>> temp_table = table[i];
            if (vp.size() != temp_table.size())
            {
                continue;
            }

            bool flag = false;

            // 4방향 회전을 위한 for문 
            for (int R = 0; R < 4; R++)
            {
                int cnt = 0; 

                for (int j = 0; j < vp.size(); j++)
                {
                    for (int k = 0; k < temp_table.size(); k++)
                    {
                        // 값이 맞는 경우 ! 칸의 갯수만큼 cnt 을 더해준다 
                        if (vp[j].first == temp_table[k].first && vp[j].second == temp_table[k].second)
                        {
                            cnt++;
                            continue;
                        }
                    }
                }

                // 맞지 않는 경우 
                if (cnt != vp.size())
                {
                    rotation(temp_table);
                    continue;
                }

                // 칸에 딱 맞는 경우 !
                answer += vp.size();
                table_visit[i] = true;
                flag = true;
                break;
            }

            if (flag == true)
            {
                break;
            }
        }
    }

    return answer;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    int answer = -1;
    
    vector<vector<pair<int, int>>> board_block;
    vector<vector<pair<int, int>>> table_block;

    // 게임보드의 빈공간 좌표를 구하고 해당 좌표를 0으로 변경함 
    for (int i = 0; i < game_board.size(); i++)
    {
        for (int j = 0; j < game_board.size(); j++)
        {
            // 빈공간이며 방문한 적이 없는 블록인 경우 블록 찾아오기 
            if (game_board[i][j] == 0 && visit[i][j] == 0)
            {
                vector<pair<int, int>> vp_block = BFS(game_board, 0, i, j);
                vector<pair<int, int>> vp_PosZero = ConvertPosZero(vp_block, game_board.size());
                board_block.push_back(vp_PosZero);
            }
        }
    }

    // 
    memset(visit, 0, sizeof(visit));

    // 테이블의 블록 좌표를 구하고 해당 좌표를 0으로 변경함 
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.size(); j++)
        {
            // 빈공간이며 방문한 적이 없는 블록인 경우 블록 찾아오기 
            if (table[i][j] == 1 && visit[i][j] == 0)
            {
                vector<pair<int, int>> vp_block = BFS(table, 1, i, j);
                vector<pair<int, int>> vp_PosZero = ConvertPosZero(vp_block, table.size());
                table_block.push_back(vp_PosZero);
            }
        }
    }

    // 최종 좌표별 매칭 
    answer = Board_Table_Matching(board_block, table_block);

    return answer;
}

int main()
{
    vector<vector<vector<int>>> gb = { {{1, 1, 0, 0, 1, 0}, 
                                        {0, 0, 1, 0, 1, 0}, 
                                        {0, 1, 1, 0, 0, 1}, 
                                        {1, 1, 0, 1, 1, 1}, 
                                        {1, 0, 0, 0, 1, 0}, 
                                        {0, 1, 1, 1, 0, 0}} ,

                                       {{0, 0, 0}, 
                                        {1, 1, 0}, 
                                        {1, 1, 1}} };


    vector<vector<vector<int>>> tb = { {{1, 0, 0, 1, 1, 0}, 
                                        {1, 0, 1, 0, 1, 0}, 
                                        {0, 1, 1, 0, 1, 1}, 
                                        {0, 0, 1, 0, 0, 0}, 
                                        {1, 1, 0, 1, 1, 0}, 
                                        {0, 1, 0, 0, 0, 0}} ,

                                       {{1, 1, 1}, 
                                        {1, 0, 0}, 
                                        {0, 0, 0}} };
    vector<int> dab = { 14,0 };

    // 총 몇 칸을 채울 수 있는지 return 하도록 solution 함수를 완성해주세요.
    for (int i = 0; i < gb.size(); i++)
    {
        int ans = solution(gb[i], tb[i]);

        if (ans == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << ans << " want = " << dab[i] << endl;
        }
    }
}