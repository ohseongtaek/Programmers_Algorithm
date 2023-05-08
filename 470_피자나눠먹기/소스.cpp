#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int pizze = 7;
    int idx = 1;
    while (true)
    {
        int sum = pizze * idx;

        if (sum >= n)
        {
            answer = idx;
            break;
        }
        else
        {
            idx++;
        }
    }


    return answer;
}