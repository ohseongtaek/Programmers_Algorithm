#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) 
{
    vector<int> answer;

    int idx = -100;

    while (true)
    {
        int sum = 0;
        for (int i = idx; i < idx + num; i++)
        {
            sum += i;
        }

        if (sum == total)
        {
            break;
        }
        idx++;
    }

    for (int i = idx; i < idx + num; i++)
    {
        answer.push_back(i);
    }


    return answer;
}