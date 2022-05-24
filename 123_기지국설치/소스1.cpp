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


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    // stations 는 오름차순으로 정렬되어있다.
    // 따라서 1번 아파트 부터 시작해서 stations 배열에 포함되지 않으면 기지국을 하나씩 설치하는 식으로 나아간다.

    int idx = 0;
    int apt = 1;

    while (apt <= n) {
        if (stations[idx] - w <= apt && apt <= stations[idx] + w) {
            apt = stations[idx] + w;
            idx++;
        }
        else {
            answer++;
            apt += 2 * w;
        }
        apt++;
    }


    return answer;
}


int main() {
    int n = 16;
    vector<int> station = { 9 };
    int w = 2;
    cout << solution(n, station, w) << endl;
    return 0;
}