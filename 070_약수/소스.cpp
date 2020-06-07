#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {

	vector<int> v;
	int result;
	int n, temp;
	cin >> n;
	int arr[50];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	result = v[0] * v.back();
	cout << result;

	/*
	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
	*/
	return 0;
}