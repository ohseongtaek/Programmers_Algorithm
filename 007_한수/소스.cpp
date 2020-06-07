#include <iostream>
using namespace std;        // 문제의 요지는 숫자를 입력했을때 해당 숫자의 공차를 물어보는 것 
bool hansoo(int a) {        // 예를들어 123은 각각 +1의 공차를 가지고있으므로 한수 
    if (a < 100)            // 213은 공차가 이상하기 때문에 한수가 아님 
        return true;
    int a1, a2, a3;
    a3 = a / 100;
    a1 = a % 10;
    a2 = a % 100 / 10;
    if (a3 - a2 == a2 - a1)
        return true;
    return false;
}
int main(void) {
    int N, count = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (hansoo(i))
            count++;
    }
    cout << count;
}