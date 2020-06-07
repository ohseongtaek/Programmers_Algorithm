#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
///////////////////////////////////
////////// 전역 변수 ///////////////
///////////////////////////////////
int N;
vector<int> v;
///////////////////////////////////
////////// 메인 함수 ///////////////
///////////////////////////////////
int main() {
    cin >> N;
    // 초기값 받기 
    int sub;
    cin >> sub;             //초기에 6 10 20 10 30 20 50 라고 치면 10값이 들어간것 
    v.push_back(sub);       //      

    // 벡터에 값 대입받기 
    for (int i = 1; i < N; i++) {
        int sub;
        cin >> sub;

        // 크기 확인.    뒤에서 부터 접근
        int vec_size = v.size();
        //cout << "vsize"<<v.size() << endl;
        for (int diff = vec_size - 1; diff >= 0; diff--) {
            // sub 가 더 크면 현재 인덱스의 다음 인덱스에 밀어 넣는다. 
            if (v.at(diff) < sub) {
                // 만약 마지막 인덱스보다 값이 크면 push 를 사용하여 추가하고, 
                // 아니면 값을 교체한다.  
                if (diff == vec_size - 1) {
                    v.push_back(sub);
                }
                else {
                    v.at(diff + 1) = sub;
                }
                break;
            }
            // 맨 첫 번째 인덱스 까지 갔는데 교체가 없으면, 0번 인덱스와 교환
            if (diff == 0) v.at(0) = sub;
        }

    }

    cout << v.size();
    return 0;
}
