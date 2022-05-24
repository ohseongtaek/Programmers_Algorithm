#include <string>
#include <vector>
#include <iostream>
#include<queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int num, snum = 0;
	vector<int> date(progresses.size());

	vector<int> temp;
	for (int i = 0; i < progresses.size(); i++) {
		num = 100 - progresses[i];
		date[i] = num / speeds[i];
		if (num % speeds[i] > 1) {
			date[i] + 1;
		}
		// 7 3 9
		temp.push_back(date[i]);

		if (snum < date[i]) {
			answer.push_back(1);
			snum = date[i];
		}
		else {
			int temp = answer.back();
			answer.pop_back();
			answer.push_back(temp + 1);
		}

	}

	/*
		for (int i = 1; i < date.size(); i++) {
			if (date[i - 1] > date[i]) {
				date[i] = date[i - 1];
			}
		}
		// 7 7 9

		for (int i = 0; i < date.size(); i++) {
			q.push(date[i]);
			int temp = q.front();
			q.pop();
			if()
		}

		for (int i = 0; i < date.size(); i++) {
			answer.push_back(date[i]);
		}
	*/
	return answer;
}