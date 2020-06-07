#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n';

int main()
{
	int n;
	int num;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	cin >> n;

	while (n--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << pq.top().second << endl;
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(num), num));
		}
	}

	return 0;
}