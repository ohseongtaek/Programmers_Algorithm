#include<iostream>
using namespace std;

int main() {
	int x, y, w, h;		
	cin >> x >> y >> w >> h;
	int g1, g2, g3, g4, k1, k2;
	g1 = x;		//6
	g2 = y;		//2
	g3 = w - x; //4
	g4 = h - y; //1
	k1 = g1 > g3 ? g3 : g1;
	k2 = g2 > g4 ? g4 : g2;
	if (k1 >= k2) {
		cout << k2;
	}
	else
		cout << k1;

	return 0;
}