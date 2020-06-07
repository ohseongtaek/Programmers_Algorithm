#include<iostream>
#include<string>
using namespace std;

int strcount(string str2) {
	int count = 0;
	for (int i = 0; i < str2.length(); i++) {
		if (str2[i] == 'c') {
			if (str2[i + 1] == '=' || str2[i + 1] == '-')
			{
				i++;
			}
		}
		else if (str2[i] == 'd') {
			if (str2[i + 1] == '-') {
				i++;
			}
			else if (str2[i + 1] == 'z' && str2[i + 2] == '=') {
				i++;
				i++;
			}
		}
		else if (str2[i] == 'l') {
			if (str2[i + 1] == 'j') {
				i++;
			}
		}
		else if (str2[i] == 'n') {
			if (str2[i + 1] == 'j') {
				i++;
			}
		}
		else if (str2[i] == 's') {
			if (str2[i + 1] == '=') {
				i++;
			}
		}
		else if (str2[i] == 'z') {
			if (str2[i + 1] == '=') {
				i++;
			}
		}
		count++;
	}
	return count;
}

int main() {
	string str;
	cin >> str;
	int AllNum;

	AllNum = strcount(str);

	cout << AllNum;
	return 0;
}