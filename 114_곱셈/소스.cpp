#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int a, b, c;

long long int pow(long long int x, long long int y) {
	if (y == 0) {
		//cout << "y==0 y=? "<<y << endl;
		return 1;
	}
	else if (y == 1) {
		//cout << "y==1 y=? "<<y << endl;
		return x;
	}
	if (y % 2 > 0) {
		//cout << "y % 2 y=? "<<y << endl;
		return pow(x, y - 1) * x;
	}
	//cout << "pow(x,y/2) y=? "<<y << endl;
	long long int half = pow(x, y / 2);
	half = half % c;
	return (half * half) % c;
}


int main() {
	cin >> a >> b >> c;
	cout << pow(a, b) % c;
	return 0;
}