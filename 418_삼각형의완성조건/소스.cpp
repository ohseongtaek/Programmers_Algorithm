#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> sides) 
{
    int answer = 0;
    
    int  t = 9999;
    t = min(t, sides[0]);
    t = min(t, sides[1]);

    answer = t * 2 - 1;


    return answer;
}