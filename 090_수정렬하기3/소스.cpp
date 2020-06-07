#include <iostream>

using namespace std;
int arr[10001] = { 0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    // 숫자 개수 카운트
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        arr[a] = arr[a] + 1;
    }

    // 각 숫자를 개수만큼 출력해주기
    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << "\n";

    return 0;
}