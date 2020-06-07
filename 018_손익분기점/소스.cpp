#include<iostream>
#include<string>
using namespace std;

int main() {
	int a;			// 생산하기전까지 비용 1000
	int b;			// 한대의 생산비용 70
	int c;			// 판매비용 170
	int result = 0;	// 출력 결과 

	cin >> a >> b >> c;
	result = c - b;				//손익분기점이 넘을라면 무조건 판매비용이 높아야하기때문에 해당조건으로 -1 을 출력한다 
	if (result <= 0) {
		cout << "-1" << endl;
	}
	else {
		cout << a / result + 1;		// 손익분기점은 무조건 원금보다 높아야되기 때문에 +1을 해주는것 
	}

	return 0;
}