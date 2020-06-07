#include<iostream>
#include<cmath>
int ost(double x1, double y1, double x2, double y2);
using namespace std;


int main() {
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		double x1, y1, r1, x2, y2, r2, k;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		k = ost(x1, y1, x2, y2);
		if (x1 == x2 && y1 == y2 && r1 == r2) {			//두 원이 완벽하게 겹칠경우 나오는 경우의 수가 무한대 
			cout << "-1" << endl;
		}
		else if (sqrt(k) > r1 + r2) {					// 밑에 함수에서 루트를 안씌우는 이유는 여기서 제거해주기 때문이다 sqrt함수로 k를 이럴경우는 만나는 경우의 수가 없는것 
			cout << "0" << endl;
		}
		else if (sqrt(k) == r1 + r2) {					// 1개인경우 두원이 바깥에서 외접하는 경우 
			cout << "1" << endl;
		}
		else if (k > pow(r1-r2,2)) {						// 생각하기 좀 어려운데 두 원점사이의 거리의 제곱이 두 반지름 사이의 제곱보다 클경우가 두원이 ∞ 식으로 겹치는것 그래서 2개 
			cout << "2" << endl;
		}
		else if (k == pow(r1 - r2, 2)) {
			cout << "1" << endl;						// 한원 안에 다른원안이있고 내접하는 경우 임 
		}
		else {
			cout << "0" << endl;						// 같은 원점을 가지고 다른 반지름을 가질때의 예외처리 
		}
	}
	return 0;
}	
int ost(double x1, double y1, double x2, double y2) {			// 두 원사이의 원점에서 거리를 구하는 함수 이다 
	return (x1 - x2)* (x1 - x2) + (y1 - y2)* (y1 - y2);		// 원래공식은 (루트 (x1-x2)제곱+(y1-y2)제곱)인데 루트만 씌우지 않는다 
}