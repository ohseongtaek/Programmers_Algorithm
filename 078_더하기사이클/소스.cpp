#include <iostream>
using namespace std;
int main()
{
	int a, count = 0, temp;
	cin >> a;

	temp = a;

	if (a < 0 || a>100) {
		return 0;
	}

	while (1) {

		int front, back;

		front = temp / 10;
		back = temp % 10;

		temp = (back * 10) + ((front + back) % 10);

		count++;
		if (a == temp) {
			cout << count << endl;
			break;
		}

	}

}