#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define endl '\n';
int main() {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	/*
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	*/
	while (1) {
		if (q.size() == 1) {
			break;
		}
		else {
			q.pop();
			q.push(q.front());
			q.pop();
		}
		
	}
	cout << q.front() << endl;
}