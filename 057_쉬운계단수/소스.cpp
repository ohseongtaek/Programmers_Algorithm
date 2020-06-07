#include<iostream>
using namespace std;
#define max 1000000000
int main() {
	int n;
	cin >> n;		//2일때 가정 10 11 .... 98 까지 가능하다 결국 점화식은 맨앞에가 1일때 0,1 
	long long arr[101][11];
	long sum = 0;

	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}
	arr[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				arr[i][j] = arr[i - 1][j + 1];
			}
			else if (j == 9) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1] % max;		// 오버플로우를 피하기위해 %max를 한다 
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = sum + arr[n][i];
	}
	cout << sum % max << endl;

	return 0;
}