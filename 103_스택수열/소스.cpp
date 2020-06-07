#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main() {
	stack<int> st;
	vector<int> v;
	vector<char> c;
	int n,k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	vector<int>::iterator iter;
	iter = v.begin();

	for (int i = 1; i <= n; i++) {
		st.push(i);
		c.push_back('+');
		while (!st.empty()) {
			if (*iter != st.top()) {
				break;
			}
			else {
				st.pop();
				c.push_back('-');
				iter++;
			}
		}
	}
	
	if (st.empty()) {
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << '\n';
		}
	}
	
	else {
		cout << "NO";
	}
	return 0;
}