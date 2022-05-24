#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string dartResult) {			//42 * //35 # //대문자 D 68, S83, T84 // 49~57 1~10 임 
	int answer = 0;

	int ind = 0;
	vector<int> v;

	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == 'S') {}
		else if (dartResult[i] == 'D') {
			v[ind - 1] = v[ind - 1] * v[ind - 1];
		}
		else if (dartResult[i] == 'T') {
			v[ind - 1] = v[ind - 1] * v[ind - 1] * v[ind - 1];
		}
		else if (dartResult[i] == '*') {
			v[ind - 1] = v[ind - 1] * 2;
			if (ind > 1) {
				v[ind - 2] = v[ind - 2] * 2;
			}
		}
		else if (dartResult[i] == '#') {
			v[ind - 1] = v[ind - 1] * -1;
		}
		else {
			if (dartResult[i + 1] == '0') {
				v.push_back(10);
				i++;
			}
			else {
				v.push_back(dartResult[i] - '0');
			}
			ind++;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		answer = answer + v[i];
	}

	return answer;
}