#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int count = 2;
	
	while (n > 1) {
		if (n % count != 0) {
			while (n % count != 0) {
				count++;
			}
		}
		n = n / count;
		cout << count << endl;
	}
	return 0;
}