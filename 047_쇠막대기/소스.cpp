#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> s;

    for (int i = 0; i < arrangement.size(); i++) {

        if (arrangement[i] == '(') {            // ( -> start, push stack
            s.push(arrangement[i]);
        }

        else {                               // ) -> end, pop stack and () -> cut -> front ( number cut
            s.pop();
            if (arrangement[i - 1] == '(') {      // () case
                answer = answer + s.size();
            }
            else {                           // )) case +1 not size
                answer++;
            }
        }
    }


    return answer;
}