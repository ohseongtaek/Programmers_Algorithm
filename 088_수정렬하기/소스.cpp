#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	int arr[1000];

	for (int i = 0; i < testcase; i++) {
		cin >> arr[i];							//1 3 2
	}

	for (int i = 0; i < testcase - 1; i++) {
		for (int j = i + 1; j < testcase; j++) {	// 123
			if (arr[j] < arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int j = 0; j < testcase; j++) {
		cout << arr[j] << endl;
	}

	return 0;
}