#include<iostream>
using namespace std;

int ostn(int x) {
	if (x == 1 || x == 0) {
		return 1;
	}
	return x * ostn(x - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	int n, r, nr, temp;
	cin >> a >> b;
	n = ostn(a);
	r = ostn(b);
	nr = ostn(a - b);
	temp = n / (r * nr);
	cout << temp;
	return 0;
}