#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << "\n" << a * b / gcd(a, b) << "\n";
}