#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
int buffer[600][600];               // 입력받을 배열 
int result[600][600];               // 결과를 저장할 배열 
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {           //만약 4라면    //층수
        for (int j = 0; j <= i; j++) {                     //층에따른 입력값
            cin >> buffer[i][j];            //0,0 부터 배열 저장해서 쭉 입력 
        }
    }
    result[0][0] = buffer[0][0];               // 00 의 배열은 결과값에 저장 
    for (int i = 1; i < n; i++) {              // 1이니깐 2번째층부터 ㄷ로린다 
        for (int j = 0; j <= i; j++) {  
            if (j == 0) {                      // j=0인경우? 는 여기서는 1,0 2,0 3,0 4,0 처럼 맨왼쪽의 대각선일경우이다 
                result[i][j] = result[i - 1][j] + buffer[i][j];     //1,0 = 0,0(첫번째수) + 입력한수를 더한것이다 
            }
            else if (j == i) {                  // j = i 인 경우는 1,1 2,2 3,3 4,4 5,5 처럼 맨 오른쪽일 경우이다 
                result[i][j] = result[i - 1][j - 1] + buffer[i][j];
            }
            else {                              // 만약 위 두개의 경우의 수가 아닌경우에는 
                result[i][j] = max(result[i - 1][j], result[i - 1][j - 1]) + buffer[i][j];
            }   // 해당 좌표로 올수있는 경우의수 2가지 왼쪽위와오른쪽위의 최대값을 가지고온 후 해다 값을 더해서 결과에 저장한다 
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {       // 0 부터 n까지 계쏙 반복 
        if (result[n - 1][i] >= max)    // 이후 입력이 4명 result[3][0] ~ result[3][3] 까지 반복핸다 이유는 맨 아래값에 결과값이 저장되어있기 때문이다 이후 max를 이용해 최대값을 넣는다 
            max = result[n - 1][i];
    }
    cout << max;
    return 0;
}