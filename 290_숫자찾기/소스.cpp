#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) 
{
    int answer = -1;

    string tmp = to_string(num);

    for (int i = 0; i < tmp.size(); i++)
    {
        if (k == tmp[i] - '0')
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}