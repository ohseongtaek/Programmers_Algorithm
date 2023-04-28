#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    string test = to_string(n);

    for (int i = 0; i < test.size(); i++)
    {
        answer += test[i]-'0';
    }

    return answer;
}