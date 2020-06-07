#include<iostream>

#define endl "\n"
#define MAX 1001
#define Moduler 10007
using namespace std;


int DP[MAX][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;
    if (N < 1 || K < 0 || K > N) {
        exit(0);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0) {
                DP[i][j] = 1;
                continue;
            }
            DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % Moduler;
        }
    }

    cout << DP[N][K] % Moduler << endl;
    return 0;
}