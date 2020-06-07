#include <iostream>
using namespace std;
#define ll long long

ll power(ll x, ll y, ll mod) {
	ll ans = 1;							//x는 n2 (분모) y 는 거듭제곱 mod 는 나눌수 
	while (y > 0) {						// 제곱이 0보다 크면 계속 제곱 해준다 
		if (y % 2 == 1) {				// 제곱이 홀수라면 x하나 곱해주고 나누값을 가지고 있는다 
			ans = ans * x;
			ans = ans % mod;
		}
		x = x * x;
		x = x % mod;
		y = y / 2;
	}
	return ans;
}

int main() {
	int N, K;
	cin >> N >> K;
	ll mod = 1000000007;
	ll n1 = 1, n2 = 1, n3;

	for (int i = 2; i <= N; i++) {		// n!/k!(n-k)! 중 n! 연산
		n1 = n1 * i;
		n1 = n1 % mod;
	}
	for (int i = 2; i <= K; i++) {		//n!/k!(n-k)! 중 k! 연산
		n2 = n2 * i;
		n2 = n2 % mod;
	}
	for (int i = 2; i <= (N - K); i++) {	//n!/k!(n-k)! 중 k!연산한것에 (n-k)! 연산 해서 분모를 말하는 변수 n2
		n2 = n2 * i;
		n2 = n2 % mod;
	}
	n3 = power(n2, mod - 2, mod);		// 위의 연산에서 / 가있으면 %할때 계산값이 다르므로 A = (n! % p) * B = {(k!(n-k)!)^p-2 % p} = 1 임을 이용해 B를 power함수에 보냄 
	n3 = n3 % mod;						// 페르마의 소정리를 사용한 이유는 수가 매우 커지는 상황에서 제곱 수가 100000087이다 이렇게 큰 수를 빠르게 처리하기 위함이며 숫자가 너무 커지는것을 방지해 연산 결과마다 %p을 해주어 값을 벗어나지 않게 해주는것이다 
	n3 = n3 * n1;						// A*B 에 대한 연산 
	n3 = n3 % mod;
	cout << n3 << '\n';
	return 0;
}