#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) 
{
    int answer = 1;
    int tmp = slice;
    while (true)
    {
        if (tmp < n)
        {
            answer++;
            tmp = tmp + slice;
        }
        else
        {
            break;
        }
    }


    return answer;
}