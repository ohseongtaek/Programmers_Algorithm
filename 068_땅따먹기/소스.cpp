#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_hap(vector<int> v, int index) {
    int temp = 0;
    for (int i = 0; i < v.size(); i++) {
        if (index != i) {
            temp = max(temp, v[i]);
        }
    }
    return temp;
}


int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            land[i][j] = land[i][j] + max_hap(land[i - 1], j);          // 1,0 의 배열에서 이전 배열과 합했을때 가장 큰 수를 리턴하는 곳 
            answer = max(answer, land[i][j]);
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> land = {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
    int dab;

    dab = solution(land);

    cout << dab << endl;
}
/*
| 1 | 2 | 3 | 5 |

| 5 | 6 | 7 | 4 |

| 4 | 3 | 2 | 1 |
*/