#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string str = "";
	
	while (1) {
		getline(cin, str);
		if (str.size() == 1 && str[0] =='.'){
			break;
		}
		int size = str.length();
		bool no = false;

		stack<char> s;
		for (int i = 0; i < size; i++) {
			if (str[i] == '[' || str[i] == '(') {
				s.push(str[i]);
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					no = true;
					break;
				}
			}
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					no = true;
					break;
				}
			}
		}
		if (!no && s.empty()) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}