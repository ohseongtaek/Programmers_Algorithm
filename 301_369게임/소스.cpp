#include <string>
#include <vector>

using namespace std;

int solution(int order) 
{
    int answer = 0;

    string test = to_string(order);

    for (int i = 0; i < test.size(); i++)
    {
        if (test[i] - '0' == 3 || test[i] - '0' == 6 || test[i] - '0' == 9)
        {
            answer++;
        }
    }

    return answer;
}