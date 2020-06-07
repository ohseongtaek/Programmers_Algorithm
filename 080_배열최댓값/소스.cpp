#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9];
	int maxy;
	int k = 1;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		maxy = max(maxy, arr[i]);
	}
	for (int j = 0; j < 9; j++) {
		if (maxy == arr[j]) {
			break;
		}


		k++;
	}

	cout << maxy << endl;
	cout << k;

	return 0;
}