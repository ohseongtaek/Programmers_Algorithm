#include<iostream>
#include<string>
using namespace std;

int main() {
	int count = 0;
	string s;
	getline(cin, s);			//한줄로 입력받기위한 함수 
	if (s.length() >= 1) {		//입력받은것이 1개 이상일때 
		if (s[0] != ' ') {		//그리고 단어의 처음이 공백이 아닐때 
			count++;			//+1	//1번째 단어는 세어진것 
		}
	}

	for (int i = 0; i < s.length(); i++) {		//0부터 시작 
		if (s[i] == ' ') {						//공백일때 
			if (s[i + 1] == ' ') {				// 다음껏도 공백일때 
				count++;						// dont [공백] [공백] money 일경우에도 셈을해야한다. 공백이후에 오는 공백은 단어취급을한다 
			}
			else if (s[i + 1]) {				// dont [공백] money 일때 셈해야하기때문에 이것도 필요 
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}