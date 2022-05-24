#include <string>
#include <vector>

using namespace std;
vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long temp = x;
    long long lx = x;
    if (lx > 0) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                answer.push_back(lx);
            }
            else {
                lx = lx + temp;
                answer.push_back(lx);
            }
        }
    }
    else if (lx == 0) {
        for (int i = 0; i < n; i++) {
            answer.push_back(lx);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                answer.push_back(lx);
            }
            else {
                lx = lx + temp;
                answer.push_back(lx);
            }
        }
    }

    return answer;
}