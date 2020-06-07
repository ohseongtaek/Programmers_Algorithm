#include<iostream>
using namespace std;

int main() {

	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	if (x == x1) {
		cout << x2 <<" ";
	}
	else if (x1 == x2) {
		cout << x<<" ";
	}
	else {
		cout << x1<<" ";
	}

	if (y == y1) {
		cout << y2;
	}
	else if (y1 == y2) {
		cout << y;
	}
	else {
		cout << y1;
	}

	return 0;
}