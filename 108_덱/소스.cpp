#include<iostream>
#include<deque>
using namespace std;
#define endl '\n';
int main() {
	int n;
	cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		if (str == "push_front") {
			int temp;
			cin >> temp;
			dq.push_front(temp);
		}
		else if (str == "push_back") {
			int temp1;
			cin >> temp1;
			dq.push_back(temp1);
		}
		else if (str == "pop_front") {
			if (dq.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (str == "size") {
			cout << dq.size() << endl;
		}
		else if (str == "empty") {
			cout << dq.empty() << endl;
		}
		else if (str == "front") {
			if (dq.empty()) {
				cout << "-1" << endl;
			}
			else{
				cout << dq.front() << endl;
			}
		}
		else if (str == "back") {
			if (dq.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << dq.back() << endl;
			}
		}
	}
	return 0;
}