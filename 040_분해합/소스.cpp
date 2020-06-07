#include<iostream>
using namespace std;
int ost(int a);

int main() {
	int num,good;
	cin >> num;					//24입력 122

	good = ost(num);			// 24로 함수 호출  122

	if (good == num) {
		cout << "0" << endl;
	}
	else {
		cout << good;
	}
	return 0;
}

int ost(int a) {			// a =24로 정의	122
	int x = 1;

	while (1) {
		int cnt = x;
		int sum = x;

		while (cnt) {				// 처음에는 1로 무조건 들어감 cnt는 처음에1부터 ~ 늘어감 만약 x=21일때 
			sum = sum + (cnt % 10);	// sum도 21임 여기서 21+1 임 그래서 22 이후 여기로 오면 sum은 22 여기서 cnt %10 은 2다 더하면 24 
			cnt = cnt / 10;			// cnt는 2다 이후 또 while	이후 여기는 0이됨 
		}

		if (x == a || sum == a) {		// 여기서 sum = a가 같아서 탈출 및 x리턴 
			break;
		}
		x++;							// x 1씩증가  122일때는 115가 생성자인데 이는
	}									// cnt =115 sum 115 처음에 while후 115+5 가 sum 임 이후 cnt/10 은 11이다 
	return x;							// 이후 또 while로 가면 sum(120)+1 이며 다시 여기서 cnt/10을만나 1이되며 마지막으로 sum(121)+1을 한다 
}										// 깨달음 while(cnt)에서 10으로 계쏙 나누면서 일의자리 십의자리 백의자리를 더해서 같으면 탈출!!!