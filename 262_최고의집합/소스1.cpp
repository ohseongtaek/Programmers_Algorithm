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



vector<int> solution(int n, int s) {
    vector<int> answer;

    // 문제 분석
    // 곱의 최대값은 숫자끼리의 차이가 가장 적어야함
    // ex ) n=127 s=3 일경우 42 42 43 이 최고의 집합이다
    // 이런 수가 나오게 하려면 n/3 = 42 이고 나머지가 1이다
    // 나머지가 2라면 오른쪽에서 2개를 +1하고 위와같은 경우에는 나머지가 1이기 때문에 맨 오른쪽 값만 +1을한다.
    // 못만드는 경우 -1 리턴

    if (n > s) {
        answer.push_back(-1);
    }
    else {
        int value = s / n;
        int percent = s % n;

        // value 을 각 idx 푸시
        for (int i = 0; i < n; i++) {
            answer.push_back(value);
        }

        /* temp code
        for(int i=0; i<answer.size(); i++){
            cout << answer[i] << endl;
        }
        */

        for (int i = 0; i < percent; i++) {
            answer[i]++;
        }

        sort(answer.begin(), answer.end());
    }
    return answer;
}

int main() {
    int n = 3;
    int k = 128;
    vector<int> a = solution(n, k);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }

    return 0;
}