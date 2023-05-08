#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) 
{
    int answer = 0;

    int one = dot[0];
    int two = dot[1];

    if (one > 0 && two > 0)
    {
        answer = 1;
    }
    else if (one > 0 && two < 0)
    {
        answer = 4;
    }
    else if (one < 0 && two > 0)
    {
        answer = 2;
    }
    else if (one < 0 && two < 0)
    {
        answer = 3;
    }

    return answer;
}