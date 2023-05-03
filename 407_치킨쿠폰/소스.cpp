#include <string>
#include <vector>

using namespace std;

int solution(int chicken) 
{
    int answer = 0;

    int coo = chicken;

    while (coo >= 10)
    {
        int eat = coo / 10;
        answer += eat;
        coo = coo % 10 + eat;
    }

    return answer;
}