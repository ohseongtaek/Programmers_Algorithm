#include<iostream>
using namespace std;

int ost(int x) {
	if (x == 0) {
		return 0;
	}
	if (x == 1) {
		return 1;
	}
	return ost(x - 1) + ost(x - 2);;
}

int main() {
	int a,pa=0;
	cin >> a;
	pa = ost(a);
	cout << pa;
	return 0;
}