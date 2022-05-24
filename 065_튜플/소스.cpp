#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;


vector<int> solution(string s) {
	vector<int> answer;
	vector<int> vpiv_tmp;
	vector<pair<int, vector<int>>> vpiv;
	int num = 0;
	for (int j = 1; j < s.length() - 1; j++) {
		if (s[j] == '{') {
			continue;
		}
		if (s[j] == '}') {
			vpiv_tmp.push_back(num);
			vpiv.push_back(make_pair(vpiv_tmp.size(), vpiv_tmp));
			num = 0;
			vpiv_tmp.clear();
		}
		else if (s[j] == ',') {
			if (s[j - 1] == '}') {
				continue;
			}
			else {
				vpiv_tmp.push_back(num);
				num = 0;
			}
		}
		else {
			num = num * 10;
			num = num + (s[j] - '0');
		}
	}

	sort(vpiv.begin(), vpiv.end());

	set<int> uniq;

	for (pair<int, vector<int>> p : vpiv) {
		for (int num : p.second) {
			if (uniq.find(num) == uniq.end()) {
				uniq.insert(num);
				answer.push_back(num);
			}
		}
	}
	return answer;
}

int main() {
	vector<int> dab;
	string str = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	string str2 = "{{123}}";
	string str3 = "{{20,111},{111}}";
	dab = solution(str3);

	for (int i = 0; i < dab.size(); i++) {
		cout << dab[i] << endl;
	}


	return 0;
}
