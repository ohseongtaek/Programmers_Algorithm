#include <iostream>
using namespace std;
int main()
{
    unsigned int dp[10001] = { 0, };
    int arr[100] = { 0, };
    int n, k, x = 0, y = 1, r = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << dp[k] << endl;
    return 0;
}