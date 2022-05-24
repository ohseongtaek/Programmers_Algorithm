#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 1234567;

long long solution(int n) {

    long long answer = 0;

    // 멀리뛰어야하는 칸  : 1   2   3   4   5   6   7   8
    // 갈수있는경우의 수  : 1   2   3   5   8   13  21  34
    int DP[2001];
    memset(DP, 0, sizeof(DP));

    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= n; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
    }

    answer = DP[n];
    return answer;
}


int main() {

    int n = 4;  // 1<=n <=20000
    long long a = solution(n);
    cout << a << endl;
    /* debug code 규칙찾기위한 코드
    vector<int> v = {1,1,2,2};

    int count = 0;
    do{
        count++;
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }

        cout << '\n';

    }while(next_permutation(v.begin(),v.end()));


    cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW = " << count << endl;
    */
    return 0;

}