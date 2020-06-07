#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	int num, don, count = 0;
	cin >> num >> don;
	vector<int> v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];	// 0 -> 1, 1->5, 2->10, 3->50 ...9-> 50000 
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < num; i++) {
		while (don - v[i] >= 0) {
			count++;
			don = don - v[i];
		}
	}
	cout << count << endl;

	return 0;
}