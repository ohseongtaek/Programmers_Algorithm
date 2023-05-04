#include <string>
#include <cstring>
#include <vector>

using namespace std;

int arr[101][101];

int x[] = { -1,-1,-1, 0,0, 1,1,1 };
int y[] = { -1, 0, 1,-1,1,-1,0,1 };

int sero = 0;
int garo = 0;

int getrange(int ty, int tx, int ry, int rx)
{
    int rrg = ry + ty;
    int rry = rx + tx;

    if (rrg < 0 || rrg >= garo || rry < 0 || rry >= sero)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int solution(vector<vector<int>> board) 
{
    vector<pair<int, int>> vp;
    
    int answer = 0;
    sero = board.size();
    garo = board[0].size();
    
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 1)
            {
                vp.push_back(make_pair(i, j));
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < vp.size(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            bool r = getrange(y[j], x[j], vp[i].first, vp[i].second);

            if (r == true)
            {
                int g2 = vp[i].first + y[j];
                int y2 = vp[i].second + x[j];
                arr[g2][y2] = 1;
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                answer++;
            }
        }
    }

    return answer;
}