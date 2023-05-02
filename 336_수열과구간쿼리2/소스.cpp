#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) 
{
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        int c = queries[i][2];
        int result = 1000000;
        bool flag = false;
        for (int j = a; j <= b; j++)
        {
            if (arr[j] > c)
            {
                flag = true;
                result = min(result, arr[j]);
            }
        }

        if (flag == true)
        {
            answer.push_back(result);
        }
        else
        {
            answer.push_back(-1);
        }
        
    }

    return answer;
}