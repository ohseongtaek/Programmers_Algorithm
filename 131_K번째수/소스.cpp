#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int end = K;
	int start = 1;
	int mid;
	int result;
	while (start <= end) {
		mid = (end + start) / 2;
		int num = 0;
		for (int i = 1; i <= N; i++) {
			num = num + min(mid / i, N);
		}
		if (num < K) {
			start = mid + 1;
		}
		else {
			result = mid;
			end = mid - 1;
		}
	}
	cout << result;

	return 0;
}