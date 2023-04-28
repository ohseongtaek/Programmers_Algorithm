#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;

    int idx = 1;
    while (true)
    {
        long long tmp = pow(idx, 2);
        if (tmp == n)
        {
            answer = 1;
            break;
        }
        
        if (tmp > n)
        {
            answer = 2;
            break;
        }
        idx++;
    }
    return answer;
}

int main()
{
    solution(144);
}