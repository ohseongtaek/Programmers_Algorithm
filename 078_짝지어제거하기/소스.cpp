#include <iostream>
#include<string>
#include <stack>
#include <vector>
using namespace std;

int solution(string s)
{
	stack<char> st;
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {
		if (st.empty() || st.top() != s[i]) {
			st.push(s[i]);
		}
		else if (st.top() == s[i]) {
			st.pop();
		}
	}

	if (st.empty()) {
		answer = true;
	}
	else {
		answer = false;
	}
	return answer;
}