#include<iostream>
using namespace std;
int ost(int x) {			//10인자로 받고 계속 곱하면 됨 
	if (x > 2) {
		x = x * ost(x - 1);
	}
	return x;
}
int main() {
	int a, sum=1;				// 0! 은 1이라서 1로 초기화시켜야함 
	cin >> a;					//10 입력

	if(a!=0){
		sum = ost(a);
	}
	cout << sum;

	return 0;
}