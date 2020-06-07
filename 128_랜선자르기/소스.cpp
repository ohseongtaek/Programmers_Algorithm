#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int N, M;
long long electricLine[MAX];

bool possible(long long len)                    //len 401 임 
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
        cnt = cnt + electricLine[i] / len;      // 4개 입력받은것을 각각 401로 나눈다 다 더하고 나눈것이랑 같음 따라서 중간값으로 나눳을때 몇개가 나오는지 나타냄 

    //cout << "cnt = ? " << cnt << endl;
    //조건 충족 여부
    if (cnt >= M)                               //  M은 가지고 싶은수 즉 11개 를 가지고 싶은것 보다 cnt가 크면 더 크게 잘라서 수를 낮춰야 하므로 true 리턴 
        return true;                            // cnt로 나눳을때 값을 계속 더해서 11개보다 많으면 더 작게 잘라야하므로 false 리턴 
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;                              // 가지고 있는 수와 가지고 싶은 수 입력 

    long long high = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> electricLine[i];                 // 가지고 있는 수의 각 랜선 길이 입력 

        high = max(high, electricLine[i]);      // 각 랜선길이중 최대값을 high변수에 저장 
    }

    long long result = 0;
    long long low = 1;                          //제일 작은값 정의 

    //이분 탐색 진행
    while (low <= high)                         // low(1) <= high(802) 이므로 들어간다 
    {
        long long mid = (low + high) / 2;       // 중간값을 찾는다 mid 여기선 401
        if (possible(mid))                      // 401 을 함수에 넣음 
        {
            // cout << "what =? " << mid << endl;// result 는 결과값을 저장하는 곳
            if (result < mid)                   // true인 경우 더 크게 잘라야 하므로 
                result = mid;
            low = mid + 1;                      // 오른쪽으로 mid값 오른쪽으로 이동 
        }
        else {
            // cout << "else what = ? " << mid << endl;
            high = mid - 1;                     // cnt가 더 작을때는 더 작게 잘라서 cnt를 11로 늘려야하므로 high 를 mid -1 을 해준다 
        }

    }
    cout << result << "\n";
    return 0;
}

