#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    int T;
    int stud[1000];
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        memset(stud, 0, sizeof(stud));
        int mean = 0;
        for (int j = 0; j < N; j++) {
            cin >> stud[j];
            mean += stud[j];
        }
        mean = mean / N;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (stud[j] > mean) {
                cnt++;
            }
        }
        cout << fixed;         // 부동소수점을 고정소수점으로 바뀜
        cout.precision(3);      // 고정소수점으로 바뀐 값0.여기부터 3자리를 출력하는것 만약 위에 fix가 없다면 밑에서 3으로 지정해주면 40.000은 안찍히게되며 
                                // precision값을 5로 바꿔줘도 안찍히며 , 소수점이 있다는 전제하에 fixed 를 쓰고 밑에 3을쓴것이랑 그냥 밑에 5를 쓴것이랑은 같다 
        cout << 100 * cnt / (double)N << "%" << endl;
    }
    return 0;
}