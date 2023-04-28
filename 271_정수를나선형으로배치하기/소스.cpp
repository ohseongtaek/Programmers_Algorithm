#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;

    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(0);
        }
        answer.push_back(v);
    }

    int i = 0;
    int j = -1;
    int k = 0;
    int sw = 1;
    int p = n;

    while (true)
    {
        for (int l = 0; l < p; l++)
        {
            k++;
            j += sw;
            answer[i][j] = k;
        }

        p--;
        if (p <= 0)
        {
            break;
        }

        for (int m = 0; m < p; m++)
        {
            k++;
            i += sw;
            answer[i][j] = k;
        }
        sw *= -1;
    }


    return answer;
}