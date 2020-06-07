#include<iostream>
#include<string>
using namespace std;

int main() {
	int bong;						//3 kg, 5kg 5kg좋아!
	cin >> bong;					// 밑에 조건문에서 5로나눌수있을때가 가장 적을때임 ㅇㅈ? 
	int count=0;					// 그러니 우리는 5로 나눌수있을때까지 -3을 한것임 
	while (1) {						// 그러면 밑에 조건문에서 결론적으로 5로 나누어떨어질때가 올거임 ex) 11 -> 3을빼고 또 3을빼면 5가됨
		if (bong % 5 == 0) {		// 그러나 7같은 경우는 절대 나누어떨어지지 않음 이럴때는 문제에서 -1을 출력하라 햇음
			count = count + (bong / 5);	//따라서 봉지수(bong)은 -3을 계속 하다보면 -3이 된다 따라서 음수로 떨어지게 되고 해당 문을 출력한다 
			break;
		}
		bong = bong - 3;
		count++;
		if (bong < 0) {
			break;
		}
	}
	if (bong < 0)
		cout << "-1" << endl;
	else
		cout << count << endl;

	return 0;
}