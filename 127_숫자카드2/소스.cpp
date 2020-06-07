#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        int temp, temp1;
        cin >> num;
        temp = upper_bound(v.begin(), v.end(), num) - v.begin();
        // upper_bound 는 정렬된 상태에서 num값을 초과한 1번째 값의 인덱스 표시 
        temp1 = lower_bound(v.begin(), v.end(), num) - v.begin();
        // lower_bound 는 정렬된 상태에서 num값을 포함한 이상의 값을 나타내기 직전의 인덱스 를 표시 
        cout << temp - temp1 << " ";
        //cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";

    }
    cout << "\n";
    return 0;
}
