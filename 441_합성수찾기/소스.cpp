#include <string>
#include <vector>

using namespace std;

bool go(int n)
{
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            num++;
        }
    }    

    if (num > 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(int n) 
{
    int answer = 0;

    for (int i = 4; i <= n; i++)
    {
        bool b = go(i);
        if (b == true)
        {
            answer++;
        }
    }


    return answer;
}