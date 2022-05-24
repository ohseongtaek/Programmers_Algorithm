#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define STRAIGHT 100
#define CORNER 500

typedef struct _pos
{
    int y;
    int x;
    int money;
    int direction;
}POS;

typedef enum _dir
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
}DIR;

int solution(vector<vector<int>> board) 
{
    // queue 를 이용한 BFS 문제 풀이 
    int answer = 10000000;

    // 순서대로 상하좌우
    int pos_y[4] = { -1, 1, 0, 0 };
    int pos_x[4] = { 0, 0, -1, 1 };

    //초기화 
    int arrMoney[25][25][4];
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                arrMoney[i][j][k] = answer;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        arrMoney[0][0][i] = 0;
    }

    queue<POS> q;
    
    // queue 초기화 
    q.push({ 0,0,0,-1 });

    while (q.empty() == 0)
    {
        int x = q.front().x;
        int y = q.front().y;
        int money = q.front().money;
        int direction = q.front().direction;

        q.pop();

        // 방향에 따른 하상우좌 비용 계산 및 vector에 넣기 
        for (int i = 0; i < 4; i++)
        {
            int temp_y = y + pos_y[i];
            int temp_x = x + pos_x[i];
            int temp_dir = i;
            int temp_money = money;

            // 범위 밖인 경우 혹은 벽인경우 
            if (temp_y < 0 || temp_y >= board.size() || temp_x < 0 || temp_x >= board.size() || board[temp_y][temp_x] == 1)
            {
                continue;
            }

            temp_money += STRAIGHT;

            // 방향이 바뀌는 경우에 500 추가 
            if (direction == UP || direction == DOWN)
            {
                if (temp_dir == LEFT || temp_dir == RIGHT)
                {
                    temp_money += CORNER;
                }
            }

            if (direction == LEFT || direction == RIGHT)
            {
                if (temp_dir == UP || temp_dir == DOWN)
                {
                    temp_money += CORNER;
                }
            }

            if (temp_money < arrMoney[temp_y][temp_x][temp_dir])
            {
                arrMoney[temp_y][temp_x][temp_dir] = temp_money;
                q.push({ temp_y,temp_x,temp_money,temp_dir });
            }
        }
    }
    
    // 전체 배열중 최솟값 찾기 
    answer = *min_element(arrMoney[board.size() - 1][board.size() - 1], arrMoney[board.size() - 1][board.size() - 1] + 4);
    return answer;
}

int main()
{
    vector<vector<vector<int>>> v = { {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}} , 
        {{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}} ,
        {{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}} ,
        {{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}} ,
        {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 0} ,{1, 1, 0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0} , {1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 0} } };

    vector<int> ans = { 900,3800,2100,3200,4500 };
        
    for (int i = 0; i < ans.size(); i++)
    {
        int test = solution(v[i]);
        if (test == ans[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << test << ", [want] = " << ans[i] << endl;
        }
    }
}

