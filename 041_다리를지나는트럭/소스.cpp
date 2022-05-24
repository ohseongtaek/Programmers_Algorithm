#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int max = 0;

	for (int i = 0; i < truck_weights.size(); i++) {

		int temp = truck_weights[i];			// 7 -> 1

		while (1) {
			if (q.empty()) {
				q.push(temp);
				max = max + temp;
				answer++;
				break;
			}
			else if (q.size() == bridge_length) {
				max = max - q.front();
				q.pop();

			}
			else {
				if (temp + max > weight) {
					q.push(0);
					answer++;
				}
				else {
					q.push(temp);
					max = max + temp;
					answer++;
					break;
				}
			}
		}
	}


	return answer + bridge_length;
}