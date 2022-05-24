#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		vector<char> vs;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			for (int k = 0; k < skill.size(); k++) {
				if (skill[k] == skill_trees[i][j]) {
					vs.push_back(skill_trees[i][j]);
				}
			}
		}
		int falg = 0;
		for (int j = 0; j < vs.size(); j++) {
			if (vs[j] != skill[j]) {
				falg = 1;
				break;
			}
		}
		if (falg == 0) {
			answer++;
		}
	}

	return answer;
}