#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) 
{
    int answer = 0;

    if (my_string.find(target) == string::npos)
    {
        answer = false;
    }
    else
    {
        answer = true;
    }

    return answer;
}
