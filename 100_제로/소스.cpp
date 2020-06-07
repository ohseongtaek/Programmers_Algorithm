#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> st;
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k != 0) {
			st.push(k);
			sum = sum + st.top();
		}
		else if (k == 0) {
			sum = sum - st.top();
			st.pop();
		}
	}
	cout << sum;

	return 0;
}