#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> vecGrid;
bool visit[510][510][4];
int nRow, nColumn;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Change_Dir(char C, int Dir)
{
    if (C == 'L')
    {
        if (Dir == 0) return 3;
        if (Dir == 1) return 2;
        if (Dir == 2) return 0;
        if (Dir == 3) return 1;
    }
    else if (C == 'R')
    {
        if (Dir == 0) return 2;
        if (Dir == 1) return 3;
        if (Dir == 2) return 1;
        if (Dir == 3) return 0;
    }
}


int ShootLight(int x, int y, int d, int len)
{
    // 방문한 좌표에 기존에 들어온 방향으로 빛이 들어온 경우에는 루프가 끝난것 혹은 기존 루프를 돌 던 값인 경우
    if (visit[x][y][d] == true)
    {
        return len;
    }

    visit[x][y][d] = true;

    int nextX = x;
    int nextY = y;
    int nextD = d;
    pair<int, int> pairChangedDir;
    if (vecGrid[x][y] != 'S')
    {
        nextD = Change_Dir(vecGrid[x][y], d);
        nextX = x + dx[nextD];
        nextY = y + dy[nextD];
    }
    else
    {
        nextX = x + dx[nextD];
        nextY = y + dy[nextD];
    }
    
    if (nextX < 0)
    {
        nextX = nRow - 1;
    }
    if (nextY < 0)
    {
        nextY = nColumn - 1;
    }
    if (nextX == nRow)
    {
        nextX = 0;
    }
    if (nextY == nColumn)
    {
        nextY = 0;
    }

    return ShootLight(nextX,nextY,nextD,len+1);

}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    // 행과 열에 대한 값 추가 및 배열 초기화 
    nRow    = grid.size();
    nColumn = grid[0].size();
    vecGrid = grid;

    // 모든 노드에서 4방향으로 빛을 발사하는 3중 for문 
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            // 0 : 아래에서 위 
            // 1 : 위에서 아래 
            // 2 : 오른쪽에서 왼쪽
            // 3 : 왼쪽에서 오른쪽 
            for (int dir = 0; dir < 4; dir++)
            {
                //빛을 i,j 노드에 있는 곳에 dir 방향으로 발사 
                int nRtn = ShootLight(i, j, dir, 0);

                // nRtn 이 0이 아닌 경우에 사이클 길이 넣기 
                if (nRtn != 0)
                {
                    answer.push_back(nRtn);
                }
            }
        }
    }

    // 오름차순 정렬 
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> t = { "SL","LR" };
    
    vector<int> test = solution(t);

    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << endl;
    }
    return 0;
}