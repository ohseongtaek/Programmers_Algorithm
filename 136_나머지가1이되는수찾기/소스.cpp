#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    while (1)
    {
        answer++;
        if (n % answer == 1)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    int a = 10;
    int dab = solution(a);
}