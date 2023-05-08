#include <string>
#include <vector>

using namespace std;

int solution(int hp) 
{
    int answer = 0;
    int tmp = hp;
    answer += tmp / 5;
    tmp = tmp % 5;

    answer += tmp / 3;
    tmp = tmp % 3;

    answer += tmp;

    return answer;
}