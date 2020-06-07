#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100000];
int temp;


void binarysearch(int x, int key) {
	int start = 0;
	int end = x - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (arr[mid] == key) {
			cout << "1" << '\n';
			return;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << "0" << '\n';
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		binarysearch(n, temp);

		/*
		if (binary_search(arr, arr + n, arr2[i])) {
			cout << "1" << '\n';
		}
		else {
			cout << "0" << '\n';
		}
		*/
	}

	return 0;
}