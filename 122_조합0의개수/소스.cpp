#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<long long, long long> numOfZero(long long N)
{
    long long two = 0, five = 0;
    for (long long i = 2; i <= N; i = i * 2)
        two = two + N / i;
    for (long long i = 5; i <= N; i = i * 5)
        five = five + N / i;
    return { two, five };
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> v(3);
    v[0] = numOfZero(N); //N!
    v[1] = numOfZero(M); //M!
    v[2] = numOfZero(N - M); //(N-M)!
    cout << min(v[0].first - v[1].first - v[2].first, v[0].second - v[1].second - v[2].second) << "\n";
    return 0;
}