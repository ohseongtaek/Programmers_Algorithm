#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 제한사항 
//n과 m은 각각 1 이상 100 이하의 자연수입니다.
//n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
//maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
//처음에 캐릭터는 게임 맵의 좌측 상단인(1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인(n, m) 위치에 있습니다.

int visit[101][101];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int sizeX = maps.size();
    int sizeY = maps[0].size();
    memset(visit, 0, sizeof(visit));
    visit[0][0] = 1;

    // X Y 축에 대한 Queue 생성 
    queue<pair<int, int>> qp;

    // 처음 좌표 푸시 
    qp.push(make_pair(0, 0));

    // 큐가 비어질때까지 동작 
    while (!qp.empty())
    {
        int CurrentX = qp.front().first;
        int CurrentY = qp.front().second;
        qp.pop();

        if (CurrentX == sizeX - 1 && CurrentY == sizeY - 1)
        {
            return visit[CurrentX][CurrentY];
        }

        // 아래 오른쪽 위 왼쪽 돌아가면서 방문 안한곳 확인 
        for (int i = 0; i < 4; i++)
        {
            int nextX = CurrentX + dir[i][0];
            int nextY = CurrentY + dir[i][1];

            if (nextX >= 0 && nextX < sizeX && nextY >= 0 && nextY < sizeY)
            {
                if (maps[nextX][nextY] == 1 && visit[nextX][nextY] == 0)
                {
                    visit[nextX][nextY] = visit[CurrentX][CurrentY] + 1;
                    qp.push({ nextX,nextY });
                }
            }
        }
    }
     
   return -1;
}

int main()
{
    vector<vector<int>> v = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };
    // return 11
    vector<vector<int>> v2 = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1} };
    // return -1
 
    int dab = solution(v);
    cout << dab << endl;

    return 0;
}