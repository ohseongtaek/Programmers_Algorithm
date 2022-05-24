#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> q;
    queue<pair<int, int>> par;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(priorities[i]);                            //  value 9 1 1 1 1 1     priorty_queue q

        par.push(make_pair(priorities[i], i));             //  value 1 1 9 1 1 1     q_pair par
    }                                                     //  index 0 1 2 3 4 5     q_pair par

    while (!q.empty()) {                                    //  value 9 1 1 1 1 1
        int value_temp = par.front().first;               //  index 2 3 4 5 0 1
        int index_temp = par.front().second;

        par.pop();

        if (q.top() != value_temp) {
            par.push(make_pair(value_temp, index_temp));
        }
        else {

            if (location == index_temp) {
                answer++;
                break;
            }
            else {
                answer++;
                q.pop();
                continue;
            }
        }
    }
    return answer;
}