#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 1000000007
int solution(int n, vector<int> money) {

    int answer = 0;
    int DP[100001];
    //0원으로 만들수 있는 경우의 수는 무조건 1개
    DP[0] = 1;

    /*  DP 배열에 누적으로 합산하기
      아래와 같은 형식으로 DP 가 나온다.
      맨 앞줄은 DP[0] 값으로 필요 X
      * 부분은 그 숫자가 추가된 부분 즉 2에 * 이있는것은 money[1] = 2이기 때문에 바로 위에 값이 추가된다.
      * 이후 부분은 그 위에 값과 새로 추가된 값만큼 왼쪽 으로 간 이후에 값을 더한것 (T) 표시된것
      1(T) 1    1(T) 1    1    1 -> money[0]
      1    1    2(*) 2    3    3 -> money[1]
      1    1    2    3(*) 4    5 -> money[2]
      1    1    2    3    5(*) 6 -> money[3]
    */
    for (int i = 0; i < money.size(); i++) {
        for (int j = money[i]; j <= n; j++) {
            DP[j] += DP[j - money[i]] % MOD;

        }
        /* Test Code
         for(int j=0; j<=n; j++){
             cout <<DP[j] <<" " ;
         }
         cout << endl;
        */
    }

    /* Test Code
    for(int i=0; i<n; i++){
        cout << DP[i] << " ";
    }
    */

    answer = DP[n];
    return answer;
}

int main() {
    int n = 5;
    vector<int> m = { 1,2,3,4 };
    int d = solution(n, m);
    cout << d << endl;
}