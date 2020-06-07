#include<iostream>
using namespace std;

int main() {

	/*
	pair<int, int> arr[50];				// 키와 몸무게를 결정하는 pair함수를 사용
	int testcase, rank = 1;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j < testcase; j++) {
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}
	*/

	int testcase, x = 1;
	int kg[50];
	int key[50];
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> kg[i] >> key[i];
	}

	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j < testcase; j++) {
			if (kg[i] < kg[j] && key[i] < key[j]) {
				x++;
			}
		}
		cout << x << " ";
		x = 1;
	}



	return 0;
}