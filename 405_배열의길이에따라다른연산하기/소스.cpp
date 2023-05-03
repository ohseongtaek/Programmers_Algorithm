#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) 
{
    vector<int> answer;

    int f = arr.size();

    if (f % 2 == 0)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0 || i == 0)
            {
                answer.push_back(arr[i]);
            }
            else
            {
                answer.push_back(arr[i] + n);
            }
        }
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0 || i == 0)
            {
                answer.push_back(arr[i] + n);
            }
            else
            {
                answer.push_back(arr[i]);
            }
        }
    }

    return answer;
}