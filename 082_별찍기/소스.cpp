#include <iostream>
using namespace std;

int main() {
	int num, k;
	cin >> num;

	if (num < 0 || num>100) {
		cout << "no";
		return -1;
	}

	k = num * 2 - 1;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = num - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}