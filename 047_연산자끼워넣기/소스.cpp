#include <iostream>
#include <vector>
using namespace std;
int n;
int resultMax = -1000000000;
int resultMin = 1000000000;
vector<int> numbers(n);
void fun(int k, vector<int> cal, int tempResult) {
	if (k == n) {
		if (tempResult > resultMax) {
			resultMax = tempResult;
		}
		if (tempResult < resultMin) {
			resultMin = tempResult;
		}
	}
	else {
		if (cal[0] > 0) {
			cal[0] --;
			fun(k + 1, cal, tempResult + numbers[k]);
			cal[0]++;
		}
		if (cal[1] > 0) {
			cal[1] --;
			fun(k + 1, cal, tempResult - numbers[k]);
			cal[1]++;
		}
		if (cal[2] > 0) {
			cal[2] --;
			fun(k + 1, cal, tempResult * numbers[k]);
			cal[2]++;
		}
		if (cal[3] > 0) {
			cal[3] --;
			fun(k + 1, cal, tempResult / numbers[k]);
			cal[3]++;
		}
	}
}

int main() {
	vector<int> cal(4);
	int temp;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		numbers.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		cin >> temp;
		cal[i] = temp;
	}

	fun(1, cal, numbers[0]);

	cout << resultMax << "\n" << resultMin;

	return 0;
}