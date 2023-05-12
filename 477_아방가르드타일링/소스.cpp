#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

int solution(int n) 
{
    int answer = 0;

    vector<unsigned long long> ullv(100001, 0);

    ullv[0] = 1;
    ullv[1] = 1;
    ullv[2] = 3;
    ullv[3] = 10;
    ullv[4] = 23;
    ullv[5] = 62;
    ullv[6] = 170;

    for (int i = 7; i <= n; i++) 
    {
        if (ullv[i - 1] + 2 * ullv[i - 2] + 6 * ullv[i - 3] + ullv[i - 4] > ullv[i - 6])
        {
            ullv[i] = ullv[i - 1] + 2 * ullv[i - 2] + 6 * ullv[i - 3] + ullv[i - 4] - ullv[i - 6];
        }
        else
        {
            ullv[i] = ullv[i - 1] + 2 * ullv[i - 2] + 6 * ullv[i - 3] + ullv[i - 4] - ullv[i - 6] + MOD;
        }
        ullv[i] %= MOD;
    }

    answer = ullv[n];

    return answer;
}

int main()
{
    solution(2);
}