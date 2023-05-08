#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) 
{
    int answer = 0;
    int idx = 0;
    int cnt = 1;
    while (true)
    {
        if (cnt == k)
        {
            answer = numbers[idx];
            break;
        }

        cnt++;
        idx += 2;
        if (idx > numbers.size() || idx == numbers.size())
        {
            idx -= numbers.size();
        }
    }

    return answer;
}