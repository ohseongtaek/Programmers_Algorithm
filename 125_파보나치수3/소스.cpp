#include<iostream>
using namespace std;
typedef long long ll;
#define mod 1000000;
ll arr[1500005];
// 피사노 주기를 통해 1,000,000으로 나눈 피보나치 수열의 반복되는 주기는 1,500,000이란 것을 알 수 있었다.
int main() {
	ll n;
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		arr[i + 2] = (arr[i + 1] + arr[i]) % mod;
	}
	cout << arr[n % 1500000] << '\n';

	return 0;
}