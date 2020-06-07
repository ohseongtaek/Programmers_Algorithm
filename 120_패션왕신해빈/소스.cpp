#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n, m, ma;
	cin >> n;
	while (n--) {
		ma = 1;
		cin >> m;
		string s;
		map<string, int> a;
		for (int i = 0; i < m; i++) {
			cin >> s >> s;
			a[s]++;
		}
		for (auto i = a.begin(); i != a.end(); i++)
			ma = ma * (i->second + 1);
		cout << ma - 1 << endl;
	}
	return 0;
}