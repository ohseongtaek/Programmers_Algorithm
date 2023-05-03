#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    int answer = 0;

    int a = 0;
    int b = 0;
    int idx = 1;

    for (int i = 0; i < num_list.size(); i++)
    {
        if (idx % 2 == 1)
        {
            a += num_list[i];
        }
        else
        {
            b += num_list[i];
        }
        idx++;
    }

    if (a > b)
    {
        answer = a;
    }
    else
    {
        answer = b;
    }

    return answer;
}