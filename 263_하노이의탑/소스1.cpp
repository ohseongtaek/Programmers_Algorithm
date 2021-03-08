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

vector<vector<int>> answer;
void ost(int n, int one, int two, int three) {
    vector<int> temp = { one,three };
    if (n == 1) {
        answer.push_back(temp);;
    }
    else {
        ost(n - 1, one, three, two); // n-1 개를 1에서 2로 이동시킨다
        answer.push_back(temp);
        ost(n - 1, two, one, three); // n-1 개를 2에서 3으로 이동시킨다
    }
}

vector<vector<int>> solution(int n) {
    //재귀함수
    ost(n, 1, 2, 3);
    return answer;
}

int main() {
    int n = 2;
    vector<vector<int>> d = solution(n);

    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d[i].size(); j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}