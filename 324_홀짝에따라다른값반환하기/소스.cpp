#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool flag = true;
    if (n % 2 == 0)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

    for (int i = 1; i <= n; i++)
    {
        if (flag == true)
        {
            if (i % 2 == 0)
            {
                answer += i * i;
            }
        }
        else
        {
            if (i % 2 == 1)
            {
                answer += i;
            }
        }
    }

    return answer;
}


