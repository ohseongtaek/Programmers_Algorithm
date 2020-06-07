#include <iostream>
#include <cmath>
using namespace std;
void ost(int n, int one, int two, int three) {
	if (n == 1) cout << one << " " << three << '\n';
	else {
		ost(n - 1, one, three, two);//1. 1번기둥의 n-1개 -> 2번 기둥으로
		cout << one << " " << three << '\n'; //2. 1번기둥 -> 3번으로
		ost(n - 1, two, one, three);//3. 2번기둥 -> 3번기둥으로
	}
}
int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';//2^n-1...pow()로 제곱하면 오답처리됨. 왜? pow()는 실수형으로 계산되기 때문..
	ost(n, 1, 2, 3);
	return 0;
}