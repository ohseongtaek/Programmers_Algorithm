#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 1;
    bool flag = false;
    int sum = 1;
    for (int i = 1; i <= 10; i++)
    {
        sum *= i;
        if (sum == n || sum * i+1 > n)
        {
            answer = i;
            flag = true;
        }

        if (flag == true)
        {
            break;
        }
    }

    return answer;
}
