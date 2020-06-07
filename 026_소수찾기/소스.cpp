#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	int sum = 0, min;
	int count = 0;
	int ncount = 0;
	cin >> num1;
	cin >> num2;

	for (int i = num1; i <= num2; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count == 2) {
			ncount++;
			sum = sum + i;
			if (ncount == 1) {
				min = i;
			}
		}
		count = 0;
	}
	if (ncount == 0) {
		min = -1;
		cout << min << '\n';
	}
	else {
		cout << sum << '\n' << min;
	}
	return 0;
}