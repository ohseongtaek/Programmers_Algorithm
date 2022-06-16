#include <string>
#include <iostream>
#include <vector>

using namespace std;

int visit[5][5];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int MinMaxAlgorithm(int posAx, int posAy, int posBx, int posBy, vector<vector<int>> &board, int N, int M)
{
    int nRtn = 0;

    // 방문한경우 => 칸이 없는경우를 의미함 
    if (visit[posAx][posAy] == true)
    {
        return 0;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        int next_x = posAx + dx[dir];
        int next_y = posAy + dy[dir];

        // 범위를 벗어나는 경우 , 이미 방문한 경우, 보드에서 처음부터 0으로 정의된 경우 
        if ((next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) || visit[next_x][next_y] || board[next_x][next_y] == false)
        {
            continue;
        }

        // 이전에 방문한 곳을 1로 함으로써 칸이 사라진걸 저장함 
        visit[posAx][posAy] = 1;

        // 재귀를 통해 A의 위치 이동에 따라 B의 위치가 이동하고 또 A의 위치가 이동하는 재귀가 생성됨 
        // 값이 짝수 => 플레이어 패배 
        // 값이 홀수 => 플레이어 승리 
        int posValue = MinMaxAlgorithm(posBx, posBy, next_x, next_y, board, N, M) + 1;

        // 해당 방향으로 간것에 대해 다시 0으로 정의해줌 
        visit[posAx][posAy] = 0;

        // 패배 -> 승리로 된 경우 
        if (nRtn % 2 == 0 && posValue % 2 == 1)
        {
            nRtn = posValue;
        }
        // 패배 -> 계속 패배 => 최댓값 도출 
        else if (nRtn % 2 == 0 && posValue % 2 == 0)
        {
            nRtn = max(nRtn, posValue);
        }
        // 승리 -> 계속 승리 => 최솟값 도출 
        else if (nRtn % 2 == 1 && posValue % 2 == 1)
        {
            nRtn = min(nRtn, posValue);
        }
    }
    return nRtn;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    int answer = -1;

    // 특정 수학적 알고리즘이 있는줄 알았으나, 찾지 못했음
    // Min Max tree Algorithm => https://blog.naver.com/zzabbo/70076811364

    int N = board.size();
    int M = board[0].size();

    answer = MinMaxAlgorithm(aloc[0], aloc[1], bloc[0], bloc[1], board, N, M);

    return answer;
}

int main()
{
    vector<vector<vector<int>>> bd = { {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
                                       {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
                                       {{1, 1, 1, 1, 1}},
                                       {{1}} };
    vector<vector<int>> a = { {1, 0},
                              {1, 0}, 
                              {0, 0}, 
                              {0, 0} };

    vector<vector<int>> b = { {1, 2},
                              {1, 2},
                              {0, 4},
                              {0, 0} };
    vector<int> dab = { 5,4,4,0 };

    for (int i = 0; i < dab.size(); i++)
    {
        int answer = solution(bd[i], a[i], b[i]);
        if (dab[i] == answer)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << ", want = " << dab[i] << endl;
        }
    }
}
