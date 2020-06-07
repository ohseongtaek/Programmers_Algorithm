#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		if (num == "push") {
			int k;
			cin >> k;
			st.push(k);
		}
		else if (num == "pop") {
			if (st.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (num == "size") {
			cout << st.size() << '\n';
		}
		else if (num == "empty") {
			if (st.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (num == "top") {
			if (st.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << st.top()<<'\n';
			}
		}
		else {
			cout << "ost" << '\n';
		}
	}
	return 0;
}