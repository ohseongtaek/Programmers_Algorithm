#include<iostream>
#include<cmath>
#define PI 3.1415926535897932
using namespace std;

int main() {
	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << pow(r, 2) * PI << endl;
	cout << pow(r, 2) * 2 << endl;


	return 0;
}