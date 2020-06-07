#include<iostream>
#include<string>
using namespace std;

int reverse(int num) {
	int il, sip, bak, sum;
	bak = num / 100;
	sip = (num / 10) % 10;
	il = num % 10;
	sum = il * 100 + sip * 10 + bak;
	return sum;
}


int main() {
	
	int num1, num2;
	cin >> num1 >> num2;
	int max;

	if (reverse(num1) > reverse(num2)) {
		max = reverse(num1);
		cout << max;
	}
	else if (reverse(num1) <= reverse(num2)) {
		max = reverse(num2);
		cout << max;
	}
		

	


	return 0;
}