#include <iostream>
using namespace std;

int main() {
	
	int arr[42] = { 0 };
	int num, count=0;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		arr[num % 42] = 1;
	}

	for(int j = 0; j < 42; j++) {
		if (arr[j] == 1) {
			count++;
		}

	}
	cout << count << endl;
	return 0;
}