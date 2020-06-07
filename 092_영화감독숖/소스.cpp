#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, count = 0, jong = 666;
	string str;
	cin >> n;
	while (jong) {
		str = to_string(jong);			// s = 666 
		if (str.find("666") != -1) {		//666찾고 있으면 count++
			count++;
		}
		if (count == n) {				// n=2 일경우 count 는 1666 까지 증가한다 
			cout << jong << endl;
			break;
		}
		jong++;
	}
	return 0;
}