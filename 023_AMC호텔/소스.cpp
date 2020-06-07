#include <iostream>
using namespace std;

int main()
{
	int testcase;
	int h, w, n;
	int x, y;

	cin >> testcase;

	while (testcase--) {
		cin >> h;
		cin >> w;
		cin >> n;

		x = n % h;			//x는 들어오는 순서를 h로 나눈 나머지다 ex 10 10 규격에 10번째 손님이면 x=0이다 여기서는 손님의 층수를 알수있다 
		y = n / h + 1;		//y는 들어오는 순서를 h로 나눈 몫에 +1을한다 ex 10 10 규격에 10번째 손님이면 y=2 이다 손님의 호수를 알수있다.

		if (x == 0) {		//만약 x가 0이면 높이는 0이된다 (1층)	예외처리이다 층수가 0일수는 없으니 10일경우 꼭대기로 보낸다 
			x = h;
		}
		if (!(n % h)) {		//만약 x가 0이아니면 y는 -1을 한다 예외처리이다 맨위층일경우에 y값은 10이라서 2가된다 따라서 1001호가 안나옴 이럴경우를 대비한 예외처리 각 10층에 대한 예외처리이다.
			y -= 1;
		}
		cout << x * 100 + y << endl;
	}

	return 0;
}