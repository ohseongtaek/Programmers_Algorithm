#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	stack<char> s;
	int size = number.length() - k;
	for (int i = 0; i < number.size(); i++) {
		char temp = number[i];

		while (!s.empty() && k > 0) {
			char value = s.top();
			if (value < temp) {
				s.pop();
				k--;
			}
			else {
				break;
			}
		}
		s.push(temp);
	}
	while (s.size() != size) s.pop();

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	reverse(answer.begin(), answer.end());
	return answer;
}