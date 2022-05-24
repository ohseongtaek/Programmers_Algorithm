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


bool found_humun_number(int& mid, int& k, vector<int>& stone) {
    int count = 0;

    for (int i = 0; i < stone.size(); i++) {
        // 연속되게 나와야 한다 따라서 나온것만큼 카운트
        if (stone[i] - mid <= 0) {
            count++;
        }
        // 중간에 끊기면 무조건 0부터 다시시작
        else {
            count = 0;
        }
        // 만약 k보다 많으면 더 적은 사람이 건너야 하기 때문에 true 리턴
        if (count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int min_number = 1;
    int max_number = *max_element(stones.begin(), stones.end());
    int mid = 0;


    while (min_number <= max_number) {

        mid = (min_number + max_number) / 2;

        // 중간값만큼의 수가 건넜을때 0보다 작은값이 k만큼 나오는지 확인한다 나오면 그만큼 건너지 못한다는 것 따라서 -1
        if (found_humun_number(mid, k, stones)) {
            max_number = mid - 1;
        }
        // k만큼 나오지 못하면 더 건널수있다는것 +1
        else {
            min_number = mid + 1;
        }
    }
    return min_number;

}

int main() {
    int n = 3;
    vector<int> a = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1, 15 };
    int d = solution(a, n);
    cout << d << endl;

    return 0;
}