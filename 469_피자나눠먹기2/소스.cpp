#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    int pizza = 6;
    int idx = 1;
    bool flag = false;

    while (true)
    {
        int sum = pizza * idx;

        if (sum % n == 0)
        {
            answer = idx;
            break;
        }
        else
        {
            idx++;
        }
    }

    return answer;
}

int main()
{
    solution(10);
}