#include<iostream>
#include<queue>
using namespace std;
#define endl '\n';

int main() {
	queue<int> q;
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
	}
	return 0;
}