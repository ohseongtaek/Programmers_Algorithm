#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, sum, avg;

	cin >> a;
	if (a <= 40)
		a = 40;

	cin >> b;
	if (b <= 40)
		b = 40;

	cin >> c;
	if (c <= 40)
		c = 40;

	cin >> d;
	if (d <= 40)
		d = 40;

	cin >> e;
	if (e <= 40)
		e = 40;

	sum = a + b + c + d + e;
	avg = sum / 5;

	cout << avg;


	return 0;
}