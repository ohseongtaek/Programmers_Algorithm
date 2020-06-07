#include <iostream>  

using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;

	if (A < 1 || B < 1 || C < 1 || A>100 || B>100 || C>100)
		return -1;
	if (A >= B && A >= C)
		if (B >= C)
			cout << B << endl;
		else
			cout << C << endl;
	else if (B >= A && B >= C)
		if (A >= C)
			cout << A << endl;
		else
			cout << C << endl;
	else
		if (B >= A)
			cout << B << endl;
		else
			cout << A << endl;

	return 0;

}