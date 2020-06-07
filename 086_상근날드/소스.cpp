#include <iostream>
using namespace std;

int main() {
	int b, b1, b2, d, d2;
	cin >> b >> b1 >> b2 >> d >> d2;

	if ((b < 100 || b>2000) || (b1 < 100 || b1>2000) || (b2 < 100 || b2>2000) || (d < 100 || d>2000) || (d2 < 100 || d2 >2000))
	{
		cout << "No!!";
		return 0;
	}

	b = b < b1 ? b : b1;
	b = b < b2 ? b : b2;

	d = d < d2 ? d : d2;

	cout << b + d - 50 << endl;
	return 0;
}
