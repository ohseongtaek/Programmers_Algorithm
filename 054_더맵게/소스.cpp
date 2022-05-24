#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> qp;
    for (int i = 0; i < scoville.size(); i++) {
        qp.push(scoville[i]);
    }
    while (qp.top() < K) {
        int first_min, second_min;
        if (qp.size() == 1) {
            return -1;
        }
        first_min = qp.top();
        // cout << first_min << endl;
        qp.pop();
        second_min = qp.top();
        // cout << second_min << endl;
        qp.pop();

        int scoville_value = first_min + (second_min * 2);

        qp.push(scoville_value);
        answer++;
    }
    if (answer == 0) {
        return answer = -1;
    }
    return answer;
}