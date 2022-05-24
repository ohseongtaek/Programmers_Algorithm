#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        v[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            continue;
        }
        for (int j = 2 * i; j <= n; j = j + i) {
            v[j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (v[i] != 0) {
            answer++;
        }
    }

    return answer;
}