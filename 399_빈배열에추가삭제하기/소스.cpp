#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) 
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        if (flag[i] == false)
        {
            int a = arr[i];
            for (int j = 0; j < a; j++)
            {
                answer.pop_back();
            }
        }
        else
        {
            int a = arr[i];
            for (int j = 0; j < a*2; j++)
            {
                answer.push_back(a);
            }
        }
    }

    return answer;
}