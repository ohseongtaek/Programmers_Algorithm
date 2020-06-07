#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int comp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}


int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	stable_sort(arr.begin(), arr.end(), comp);


	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}


	return 0;
}