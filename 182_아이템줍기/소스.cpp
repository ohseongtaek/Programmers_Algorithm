#include <string>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int board[101][101];

void SHOW_BOARD()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    memset(board, 0, sizeof(board));

    // 전체적으로 * 2 (Case 1번 을 확인하다가 겹치는곳이 발생해서 곱함)
    int Cx = characterX * 2;
    int Cy = characterY * 2;

    int Ix = itemX * 2;
    int Iy = itemY * 2;

    // 사각형 좌표를 모두 1로 채우기 
    for (int i = 0; i < rectangle.size(); i++)
    {
        int start_x = rectangle[i][0] * 2;
        int start_y = rectangle[i][1] * 2;
        int end_x = rectangle[i][2] * 2;
        int end_y = rectangle[i][3] * 2;

        for (int x = start_x; x <= end_x; x++)
        {
            for (int y = start_y; y <= end_y; y++)
            {
                board[x][y] = 1;
            }
        }
    }

    // 직사각형의 테투리만 필요하기 때문에 내부는 0으로 다시 초기화 
    for (int i = 0; i < rectangle.size(); i++)
    {
        int start_x = rectangle[i][0] * 2;
        int start_y = rectangle[i][1] * 2;
        int end_x = rectangle[i][2] * 2;
        int end_y = rectangle[i][3] * 2;

        for (int x = start_x + 1; x < end_x; x++)
        {
            for (int y = start_y + 1; y < end_y; y++)
            {
                board[x][y] = 0;
            }
        }
    }

    // 시작 좌표부터 목표 좌표 까지 가는것 최소값 찾기 (BFS)
    queue<pair<int, int>> q; // 좌표를 나타내는 Queue
    q.push(make_pair(Cx, Cy));

    int dy[] = { 0,0,-1,1 };
    int dx[] = { 1,-1,0,0 };

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == Ix && y == Iy)
        {
            break;
        }

        // 4방향 
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (board[nextX][nextY] == 1)
            {
                q.push(make_pair(nextX, nextY));
                board[nextX][nextY] = board[x][y] + 1;
            }
        }
    }
    //SHOW_BOARD();
    return board[Ix][Iy] / 2;
}

int main()
{
    vector<vector<vector<int>>> r = { {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}} ,
                                      {{1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}} ,
                                      {{1, 1, 5, 7}} ,
                                      {{2, 1, 7, 5}, {6, 4, 10, 10}} ,
                                      {{2, 2, 5, 5}, {1, 3, 6, 4}, {3, 1, 4, 6}} };
    vector<int> chx = { 1,9,1,3,1 };
    vector<int> chy = { 3,7,1,1,4 };
    vector<int> ix = { 7,6,4,7,6 };
    vector<int> iy = { 8,1,7,10,3 };

    vector<int> dab = { 17,11,9,15,10 };

    for (int i = 0; i < dab.size(); i++)
    {
        int ans = solution(r[i], chx[i], chy[i], ix[i], iy[i]);

        if (dab[i] == ans)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << ans << ", want = " << dab[i] << endl;
        }
    }

    return 0;
}



/*
제한사항
rectangle의 세로(행) 길이는 1 이상 4 이하입니다.
rectangle의 원소는 각 직사각형의 [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y] 좌표 형태입니다.
직사각형을 나타내는 모든 좌표값은 1 이상 50 이하인 자연수입니다.
서로 다른 두 직사각형의 x축 좌표, 혹은 y축 좌표가 같은 경우는 없습니다.
문제에 주어진 조건에 맞는 직사각형만 입력으로 주어집니다.
charcterX, charcterY는 1 이상 50 이하인 자연수입니다.
지형을 나타내는 다각형 테두리 위의 한 점이 주어집니다.
itemX, itemY는 1 이상 50 이하인 자연수입니다.
지형을 나타내는 다각형 테두리 위의 한 점이 주어집니다.
캐릭터와 아이템의 처음 위치가 같은 경우는 없습니다.
전체 배점의 50%는 직사각형이 1개인 경우입니다.
전체 배점의 25%는 직사각형이 2개인 경우입니다.
전체 배점의 25%는 직사각형이 3개 또는 4개인 경우입니다.


*/
