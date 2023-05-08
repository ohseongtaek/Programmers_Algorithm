#include <string>
#include <vector>

using namespace std;

int solution(string my_string) 
{
    int answer = 0;
    
    for (int i = 0; i < my_string.size(); i++)
    {
        char tmp = my_string[i];

        if (tmp >= '0' && tmp <= '9')
        {
            answer += tmp - '0';
        }
    }

    return answer;
}