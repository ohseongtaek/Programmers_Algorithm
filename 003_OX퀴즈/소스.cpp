#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {

	int AllReturn;
	int testReturn = 0 ;
	int count=0;
	int sum=0;
	char OX[80] = { 0 };

	cin >> AllReturn;

	while (AllReturn > testReturn) {
		cin >> OX;

		for (int i = 0; i < strlen(OX); i++) {

			if (OX[i] == 'O') {
				count++;
				sum = sum + count;
			}
			else {
				count = 0;
			}
		}
		cout << sum << endl;
		sum = 0;
		count = 0;
		testReturn++;
	}
	return 0;
}