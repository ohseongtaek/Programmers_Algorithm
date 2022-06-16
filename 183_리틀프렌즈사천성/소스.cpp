#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct BFS_INFO
{
    int x;
    int y;
    int dir;
    int cnt;
};

bool BFS(int x, int y, int x1, int y1, vector<string>& board, int m, int n)
{
    int dx[] = { 1,0,-1,0 };
    int dy[] = { 0,1,0,-1 };

    queue<BFS_INFO> q;

    q.push({ x,y,-1,0 });

    while (q.empty() == false)
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_dir = q.front().dir;
        int current_change_dir_cnt = q.front().cnt;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            // 뒤로 간다면 continue -> 최솟값이 될 수 없기 때문에 
            if (current_dir != -1 && abs(current_dir - i) == 2)
            {
                continue;
            }
            
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            int next_change_dir_cnt = 0;

            // 방향이 다르다면 틀어야 하기 때문에 
            if ((current_dir == i || current_dir == -1))
            {
                next_change_dir_cnt = current_change_dir_cnt;
            }
            else
            {
                next_change_dir_cnt = current_change_dir_cnt + 1;
            }

            if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n)
            {
                if (next_change_dir_cnt <= 1)
                {
                    // 벽돌인경우 바로 continue;
                    if (board[next_x][next_y] == '*')
                    {
                        continue;
                    }
                    // 일반 비어있는 블록인 경우 해당 위치에서 BFS 돌아야해서 queue 푸시 
                    else if (board[next_x][next_y] == '.')
                    {
                        q.push({ next_x,next_y,i,next_change_dir_cnt });
                    }
                    else
                    {
                        // 짝를 찾은 경우 
                        if (next_x == x1 && next_y == y1)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

string solution(int m, int n, vector<string> board) 
{
    string answer = "";

    // A ~ Z => 26개 로 벡터 초기화 26개의 타일에 각 좌표값을 지정함 (순서대로 리턴해야하기 때문에 A~Z 까지 결정함)
    // A ~ Z ( vp[A][0] , vp[A][1] ) 
    vector<vector<pair<int, int>>> vp(26, vector<pair<int, int>>());

    // 제거를 해야할 갯수 
    int RemoveTile = 0;

    // loop 돌면서 찾아야 하는지 확인하는 변수 
    bool find_flag = true;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Board 값이 타일인 경우 
            if ('A' <= board[i][j] && board[i][j] <= 'Z')
            {
                vp[int(board[i][j]) - int('A')].push_back(make_pair(i, j));
                RemoveTile++;
            }
        }
    }

    while (find_flag)
    {
        // 일단 false로 초기화 
        find_flag = false;

        // A ~ Z 까지 검사
        for (int i = 0; i < vp.size(); i++)
        {
            //만약 2개의 값이 들어가 있다면(제거해야할 타일) 모든 경우의수를 이용해서 검사한다.
            if (vp[i].size() > 1)
            {
                if (BFS(vp[i][0].first, vp[i][0].second, vp[i][1].first, vp[i][1].second, board, m, n))
                {
                    // 짝을 찾은 경우에는 해당 타일을 모두 빈공간으로 만들어줘야함 
                    board[vp[i][0].first][vp[i][0].second] = '.';
                    board[vp[i][1].first][vp[i][1].second] = '.';

                    // 벡터에서 해당 정보 없어져야함 
                    vp[i].clear();

                    // 전체 제거해야할 타일중 2개 타일을 제거 
                    RemoveTile -= 2;

                    answer += char(i + int('A'));
                    find_flag = true;
                    break;
                }
            }
        }
    }

    if (RemoveTile != 0)
    {
        answer = "IMPOSSIBLE";
    }

    return answer;
}

// * -> 벽돌 
// . -> 빈칸 

int main()
{
    vector<int> m = { 3,2,4,2 };
    vector<int> n = { 3,4,4,2 };

    vector<vector<string>> b = { {"DBA", "C*A", "CDB"} ,{"NRYN", "ARYA"} ,{".ZI.", "M.**", "MZU.", ".IU."} ,{"AB", "BA"} };

    vector<string> dab = { "ABCD","RYAN","MUZI","IMPOSSIBLE" };

    for (int i = 0; i < dab.size(); i++)
    {
        string answer = solution(m[i], n[i], b[i]);

        if(answer == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << ", want = " << dab[i] << endl;
        }
    }
    return 0;
}
