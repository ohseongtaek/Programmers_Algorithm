#include <string>
#include <vector>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) 
{
    bool answer = true;

    bool t = x1 | x2;
    bool t2 = x3 | x4;

    answer = t & t2;

    return answer;
}