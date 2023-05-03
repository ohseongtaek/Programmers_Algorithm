#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int temp = 2;
    int idx = 0;
    
    while (true)
    {
        temp = pow(2, idx);
        if (temp < arr.size())
        {
            idx++;
        }
        else
        {
            break;
        }
    }

    answer = arr;

    for (int i = answer.size(); i < temp; i++)
    {
        answer.push_back(0);
    }

    return answer;
}