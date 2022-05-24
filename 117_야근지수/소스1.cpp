#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <queue>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;

    // Push
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }

    // Loop
    while (n != 0 && pq.top() > 0) {
        int pq_big = pq.top();
        pq.pop();
        pq_big--;
        n--;
        pq.push(pq_big);
    }

    // Plus
    while (!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}
int main() {
    int n = 1;
    vector<int> v = { 2,1,2 };
    long long a = solution(n, v);
    cout << a << endl;
    return 0;
}