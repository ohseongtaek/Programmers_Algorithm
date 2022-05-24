#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//char c[1000];

string solution(string s) {
	string answer = "";
	vector<int> v;
	int c = 0;
	int temp = 0;
													//0 1 2 3 4 5 6		i 값의 증가 
	for (int i = 0; i < s.size(); i++) {			//4   2 3   3 2		s 의 문자열 
		if (s[i] == ' ') {
			v.push_back(stoi(s.substr(c, temp)));
			c = i + 1;
			temp = 0;
		}
		temp++;
	}
	v.push_back(stoi(s.substr(c, temp)));
	sort(v.begin(), v.end());

	answer = to_string(v.front()) + " " + to_string(v.back());

	return answer;
}

int main() {
	string str = "4 24 32";
	//string s = solution(str);

	cout << solution(str);
}