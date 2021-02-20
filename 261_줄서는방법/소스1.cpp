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


long long factorial(int a) {

    if (a == 1) {
        return 1;
    }
    else {
        return a * factorial(a - 1);
    }
}


vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> temp_arr;
    long long first_number_slice, now_idx;


    for (int i = 1; i <= n; i++) {
        temp_arr.push_back(i);
    }

    while (1) {
        if (n == 0) {
            break;
        }
        // 해당 코드는 맨 앞자리 숫자에 따라 나올수있는 경우의 수는 모두 같음 4개 일때 각 6개씩 이걸 나타낸 코드
        first_number_slice = factorial(n) / n;

        // 현재 인덱스 값을 나타내는 코드
        // k-1 은 n=4 k=6 일 경우에 k 값이 나누어떨어지기 때문에 -1 을 해준다.
        now_idx = int((k - 1) / first_number_slice);

        // 현재 인덱스 값을 answer 벡터에 푸시
        answer.push_back(temp_arr[now_idx]);

        // 사용한 인덱스는 삭제한다 다시는 오지 않을 수 이기 때문에
        temp_arr.erase(temp_arr.begin() + now_idx);

        // 배열이 줄었으므로 다시 자르고 경우의수를 찾아야한다 따라서 n--
        n--;

        // 자리의 수가 고정될때마다 k 번째 수는 무조건 변경된다
        // ex : 4 5 에서 처음 1이 고정되면 6가지의 뽑기수가 있지만 두번째숫자가 고정되면 2개의 경우의 수밖에 없다 이때 k =5 이면 문제가 생기므로 값을 적절히 나눈다.
        k %= first_number_slice;

        // 마지막 배열을 넣기 위해서 있는 예외처리 !!!(생각하지 못한곳 30분 소요)!!!
        if (k == 0) {
            k = first_number_slice;
        }
    }
    return answer;
}

int main() {
    int n = 4;
    int k = 5;
    vector<int> a = solution(n, k);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
    return 0;
}