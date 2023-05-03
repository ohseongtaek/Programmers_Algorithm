#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int idx = 0;

    while (true)
    {
        if (idx >= arr.size())
        {
            break;
        }
        if (answer.empty() == true)
        {
            answer.push_back(arr[idx]);
            idx++;
        }
        else if (answer.empty() == false && answer[answer.size() - 1] == arr[idx])
        {
            answer.pop_back();
            idx++;
        }
        else if (answer.empty() == false && answer[answer.size() - 1] != arr[idx])
        {
            answer.push_back(arr[idx]);
            idx++;
        }
    }

    if (answer.empty() == true)
    {
        answer.push_back(-1);
    }

    return answer;
}