#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    int days = 0, index = 0;
    priority_queue<int> pq;

    while (days < k) {                  // day end loop
        if (days >= dates[index]) {     // days와 dates의 배열에 대해 일단 pq로 push한다
            pq.push(supplies[index]);
            index++;
        }
        if (stock == 0) {               //만약 남아있는 밀가루가 없으면 pq에 있는 가장 큰 수를 사용한다 이때 사용하는 값이 공급받는 것이다
            stock += pq.top();
            pq.pop();
            answer++;
        }
        days++;
        stock--;
    }
    return answer;
}