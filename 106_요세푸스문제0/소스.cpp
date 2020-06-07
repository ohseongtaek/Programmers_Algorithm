#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	queue<int> q;
	vector<int> v;
	int n;
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (1) {
		if (q.size() == 0) {
			break;
		}

		if(q.size()>1){
			for (int i = 1; i <= k; i++) {
				if (i == k) {
					v.push_back(q.front());
					q.pop();
				}
				else {
					q.push(q.front());
					q.pop();
				}
			}
		}
		else {
			v.push_back(q.front());
			q.pop();
		}
	}
	cout << "<";
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			cout << v[i] << ">";
		}
		else {
			cout << v[i] << ", ";
		}
	}
	//cout << v[v.size()] << ">";
	return 0;
}