#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) 
{
    int answer = 0;

    int temp = n / 10;

    answer += (12000 * n) + (2000 * k) - (temp * 2000);

    return answer;
}