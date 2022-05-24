#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name) {
	int answer = 0;
	string str = "";
	int minChar = 0;
	int BB = name.length();
	int Last_index = BB - 1;

	for (int i = 0; i < name.size(); i++) {
		str += str + "A";
	}
	// str = AAAAA -> name size 

	for (int i = 0; i < name.size(); i++) {
		int front = name[i] - 'A';
		int back = 'Z' - name[i] + 1;
		minChar += min(front, back);     // 문자 바꾸기 count

		/*
		if (front <= back) {            // 해당 조건문 name 만들기임
			str[i] = 'A' + front;
		}
		else {
			str[i] = 'Z' - back + 1;
		}
		*/
		int next_char = i + 1;

		while (next_char < BB && name[next_char] == 'A') {
			next_char++;
		}

		Last_index = min(Last_index, i + BB - next_char + min(i, BB - next_char));
	}
	minChar += Last_index;
	answer = minChar;
	return answer;
}