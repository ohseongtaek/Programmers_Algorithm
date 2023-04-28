#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) 
{
    int answer = 0;

    if (str2.find(str1) == string::npos)
    {
        answer = false;
    }
    else
    {
        answer = true;
    }

    return answer;
}