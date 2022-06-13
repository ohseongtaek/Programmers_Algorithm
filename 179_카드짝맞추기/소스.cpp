#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// 매우 어려웠다. => https://yabmoons.tistory.com/624 설명 정독 후 구현 

// 최대 카드갯수는 6개임 
#define CARD 7
#define MAX 4

// 카드 리스트 벡터 
vector<int> card_list;
// 카드 위치의 벡터
vector<pair<int, int>> card_pos[CARD];
// 카드를 지우기 위해 선택 여부 확인용 벡터 
vector<bool> Select(CARD, false);
// 어떤 카드를 먼저 지우는지 선택하는 벡터 
vector<int> card_order;
// 같은 카드중에서 어떤 카드를 지우는지 선택하는 벡터 
vector<int> same_card_order;

//방향 관련 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int BFS(int x, int y, int cnt, int card, int idx, vector<vector<int>>& MAP)
{
    if (cnt == 2)
    {
        return 0;
    }

    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visit(MAP.size(), vector<bool>(MAP.size(), false));
    q.push(make_pair(make_pair(x, y), 0));
    visit[x][y] = true;

    int tx, ty;

    if (cnt == 0)
    {
        tx = card_pos[card][idx].first;
        ty = card_pos[card][idx].second;
    }
    else
    {
        tx = card_pos[card][!idx].first;
        ty = card_pos[card][!idx].second;
    }

    while (q.empty() == 0)
    {
        int wx = q.front().first.first;
        int wy = q.front().first.second;
        int wCnt = q.front().second;
        q.pop();

        if (wx == tx && wy == ty)
        {
            MAP[wx][wy] = 0;
            wCnt += BFS(wx, wy, cnt + 1, card, idx, MAP);
            return wCnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = wx + dx[i];
            int ny = wy + dy[i];

            // 정상 범위인 경우 
            if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
            {
                if (visit[nx][ny] == false)
                {
                    visit[nx][ny] = true;
                    q.push(make_pair(make_pair(nx, ny), wCnt + 1));
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = wx + dx[i];
            int ny = wy + dy[i];
            while (1)
            {
                if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
                if (MAP[nx][ny] != 0)
                {
                    break;
                }

                nx += dx[i];
                ny += dy[i];
            }

            if (visit[nx][ny] == false)
            {
                visit[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), wCnt + 1));
            }
        }
    }
}


// 같은 카드 중에서 어떤것을 제거해야하는지 정하는 중복순열 구현 
void get_same_card_order(int Cnt, vector<vector<int>> MAP, int r, int c, int& answer)
{
    if (Cnt == card_list.size())
    {
        int Result = 0;
        int x = r;
        int y = c;
        vector<vector<int>> T_MAP = MAP;
        for (int i = 0; i < card_list.size(); i++)
        {
            int Card = card_order[i];
            int Idx = same_card_order[i];
            Result += BFS(x, y, 0, Card, Idx, T_MAP);

            x = card_pos[Card][!Idx].first;
            y = card_pos[Card][!Idx].second;
        }
        answer = min(answer, Result);
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        same_card_order.push_back(i);
        get_same_card_order(Cnt + 1, MAP, r, c, answer);
        same_card_order.pop_back();
    }
}

// 순열로 카드를 제거하는 순서를 모두 파악하기 위해 함수 생성 
void get_Card_Order(int Cnt, vector<vector<int>> MAP, int r, int c, int& answer)
{
    // count  가 같은 경우 같은 카드에서 삭제를 하기 위해 들어감 
    if (Cnt == card_list.size())
    {
        get_same_card_order(0, MAP, r, c, answer);
        return;
    }
    for (int i = 0; i < card_list.size(); i++)
    {
        if (Select[i] == true)
        {
            continue;
        }
        Select[i] = true;
        card_order.push_back(card_list[i]);
        get_Card_Order(Cnt + 1, MAP, r, c, answer);
        card_order.pop_back();
        Select[i] = false;
    }
}


// 뒤집어야 할 카드 위치 구해오기 
void get_card_pos(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            // 비어있는 경우에 continue;
            if (board[i][j] == 0)
            {
                continue;
            }

            card_pos[board[i][j]].push_back(make_pair(i, j));
        }
    }
}

// 카드 존재하는 리스트들 가져오기 
void get_exist_card_list(vector<vector<int>> board)
{
    // 카드 존재 여부 벡터 
    vector<int> exist_card(CARD, false);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            // 비어있는경우
            if (board[i][j] == 0)
            {
                continue;
            }
            // 카드를 넣을때 한번도 안넣은 경우 
            if (exist_card[board[i][j]] == false)
            {
                exist_card[board[i][j]] = true;
                card_list.push_back(board[i][j]);
            }
        }
    }
}


int solution(vector<vector<int>> board, int r, int c)
{
    int answer = 987654321;

    get_exist_card_list(board);
    get_card_pos(board);

    get_Card_Order(0, board, r, c, answer);
    answer += (card_list.size() * 2);

    return answer;
}

int main()
{
    vector<vector<int>> v = { {1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0} };
    // x y 축 기본 값 
    vector<int> r = { 1 };
    vector<int> c = { 0 };
    vector<int> dab = { 14 };

    int ans = solution(v, r[0], c[0]);
    if (ans == dab[0])
	{
		cout << " good " << endl;
	}
	else
	{
		cout << " error = " << ans << " , want = " << dab[0] << endl;
	}
}