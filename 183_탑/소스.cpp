#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    deque<int> dq;

    for (int i = heights.size() - 1; i >= 0; i--) {

        int temp = 0;
        if (i != 0) {
            for (int j = i - 1; j >= 0; j--) {
                if (heights[i] < heights[j]) {
                    temp = j + 1;
                    dq.push_front(temp);
                    break;
                }
                else {
                    if (j == 0) {
                        dq.push_front(temp);
                    }
                    continue;
                }
            }
        }
        else {
            dq.push_front(0);
        }
    }

    for (int i = 0; i < dq.size(); i++) {
        answer.push_back(dq[i]);
    }
    return answer;
}