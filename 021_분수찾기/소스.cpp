#include <iostream>
using namespace std;

int main()
{													//분수 위치 알아내는문제 
	int num;
	cin >> num;		//2								//짝수와 홀수를 잘 생각해봐야함 짝수일때는 
	int i;
	for (i = 1; num > 0; i++)						//i값과 num값으로 노는것임 
	{												//i는 반복되는 수이며 홀수일때는 
		num = num - i;	//num=-1 i=3		
	}
	if (i % 2 == 1)									//짝수일때 여기로 가는것임 num이 짝수일때 이유는 for문돌면서 i값이 홀수가 됨
	{
		cout << i + num - 1 << "/" << 1 - num << endl;	// 1/2
	}
	else if (i % 2 == 0)							//sum이 홀수일때 여기로 옴 for문돌면서 i가 짝수가됨 
	{		
		cout << 1 - num << "/" << i + num - 1 << endl;
	}
	return 0;
}
