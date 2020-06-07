#include<iostream>
using namespace std;

int main() {
	int n, testcase;
	long long arr[101] = {0,1,1,1,2,2,3,4,5,7,9};
	cin >> testcase;

	for (int i = 11; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	for (int i = 0; i < testcase; i++) {
		cin >> n;
		cout << arr[n] << endl;
	}
	return 0;
}