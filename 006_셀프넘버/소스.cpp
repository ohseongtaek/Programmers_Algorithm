#include<iostream>
using namespace std;
int d(int n);
int main() {

	bool arr[10001] = { false };

	for (int i = 1; i <= 10000; i++) {
		int num = d(i);						//1~10000 까지 들어가는 배열 3이라고 하면 
		if (num <= 10000) {					// 리턴값이 6이라서 해당 함수에 들어온다 
			arr[num] = true;				// 따라서 해당 값은 arr[3]에는 true가 된다. 생성자가 있는 것은 모두 ture로 바꿈 
		}
	}
	for (int j = 1; j <= 10000; j++) {		// 출력하는 for문이다 생성자 false인것을 출력한다 따라서 생성자가 없는것들이다.
		if (!arr[j])
			cout << j << endl;
	}


	return 0;
}

int d(int n) {
	int sum;
	sum = n;

	while ( n != 0 ) {
		sum = sum + n % 10;						//예로 3이 들어오면 sum = 6 이 된다 
		n = n / 10;								// dlgn n = 0.9 쯤이되며 여기선 int라서 0이된다 이후 리턴값은 6이다.
	}
	
	return sum;
}