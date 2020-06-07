#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int a, b, c;

	while(1){
		cin >> a >> b >> c;
		double a2, b2, c2, sum;
		if (a >= 30000 || b >= 30000 || c >= 30000) {
			return -1;
		}


		if (a == 0 && b == 0 && c == 0) {
			break;
			return -1;
		}

		a2 = pow(a, 2);
		b2 = pow(b, 2);
		c2 = pow(c, 2);
		if ((a2+b2 == c2) || (a2+c2==b2) || (b2+c2==a2)) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
		//cout << a2 << b2 << c2;
	}


	return 0;
}