#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    int answer = 0;

    string t1 = to_string(a) + to_string(b);
    
    int tt1 = stoi(t1);
    int tt2 = 2 * a * b;

    if (tt1 > tt2)
    {
        answer = tt1;
    }
    else
    {
        answer = tt2;
    }


    return answer;
}