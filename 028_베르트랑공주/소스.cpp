#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, root, M, N, cnt;
    while (1) {
        cin >> n;
        if (!n)
            break;

        //n보다 크고
        M = n + 1;
        //2n보다 작거나 같은
        N = n * 2;

        cnt = 0;

        for (int i = M; i <= N; i++) {
            root = sqrt(i);
            //2또는 3일 경우
            if (root == 1 && i != 1) {
                cnt++;
            }
            //n보다 크고 2보다 작거나 같은 수가 홀수일 경우(짝수이면 소수가 아니므로)
            if (i % 2) {
                for (int j = 2; j <= root; j++) {
                    //나머지가 0이면 소수가 아니다. 종료.
                    if (!(i % j))
                        break;
                    //바깥에 빼도 되지만 뺄라면 j값도 알고 있어야 함.
                    if (j == root) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}