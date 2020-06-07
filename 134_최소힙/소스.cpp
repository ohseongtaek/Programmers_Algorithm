#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define endl '\n';

priority_queue<int, vector<int>, greater<int> > pq;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}
}