#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;
#define INF 987654321

int diff[11][11];

int solve(int N, int M, vector<int> &vec) 
{
    int ret = 0;
    int temp[11][11];

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            temp[i][j] = diff[i][j];
        }
            
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp[vec[i]][j] ^= 1;
        }
        ret++;
    }

    for (int j = 0; j < M; j++) 
    {
        if (temp[0][j] == 1)
        {
            ret++;
        }
        for (int i = 1; i < N; i++) 
        {
            if (temp[i][j] != temp[0][j]) 
            {
                return INT_MAX;
            }
        }
    }
    return ret;
}

void ALLCase(int idx, int N, int M, int &answer, vector<int> &vec) 
{
    if (idx == N) 
    {
        answer = min(answer, solve(N,M,vec));
        return;
    }
    vec.push_back(idx);
    ALLCase(idx + 1, N, M, answer, vec);
    vec.pop_back();
    ALLCase(idx + 1, N, M, answer, vec);
}

int solution(vector<vector<int>> beg, vector<vector<int>> tar) 
{
    int N = beg.size();
    int M = beg[0].size();
    vector<int> vec;
    int answer = INT_MAX;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (beg[i][j] != tar[i][j])
            {
                diff[i][j] = 1;
            }
            else
            {
                diff[i][j] = 0;
            }
        }
    }

    ALLCase(0, N, M, answer, vec);

    if (answer == INT_MAX)
    {
        return -1;
    }
    else
    {
        return answer;
    }
}