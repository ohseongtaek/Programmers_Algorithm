#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);


	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}