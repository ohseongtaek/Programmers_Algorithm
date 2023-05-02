#include <string>
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

        for (int j = a; j <= b; j++)
        {
            if (j == 0)
            {
                arr[j]++;
            }
            else
            {
                if (j % c == 0)
                {
                    arr[j]++;
                }
            }
        }
    }
    answer = arr;


    return answer;
}