#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

//플로이드 와샬 알고리즘

int humun[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    memset(humun, 0, sizeof(humun));

    //승부가 정해져있으면 1로 init
    for (int i = 0; i < results.size(); i++) {
        humun[results[i][0]][results[i][1]] = 1;
    }

    //a->b , b->c , a->c 에 대한 이해관계도에 대해서 1로 set
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (humun[j][i] == 1 && humun[i][k] == 1) {
                    humun[j][k] = 1;
                    //cout << "j ? " << j << " k ? " << k << endl;
                }
            }
        }
    }

    //사람수 -1 만큼 있으면 순위가 확실한 것
    for (int i = 1; i <= n; i++) {
        int humun_count = 0;
        for (int j = 1; j <= n; j++) {
            //4 2 2 4 이런 경우는 말이 안되기 때문에 둘중 하나라도 1이면 set
            humun_count += (humun[i][j] + humun[j][i]);
        }
        if (humun_count == n - 1) {
            answer++;
        }
    }

    return answer;
}


int main() {
    int n = 5;
    vector<vector<int>> g = { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} };
    cout << solution(n, g) << endl;
}