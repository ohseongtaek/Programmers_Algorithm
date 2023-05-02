#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> answer;

    answer.push_back(n);

    bool flag = false;

    while (true)
    {
        if (n % 2 == 0)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }

        if (flag == true)
        {
            n = n / 2;
        }
        else
        {
            n = n * 3 + 1;
        }

        answer.push_back(n);

        if (n == 1)
        {
            break;
        }
    }


    return answer;
}