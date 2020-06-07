#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int N;
long long M;
long long tree[MAX];

bool possible(long long height)
{
    long long len = 0;
    //나무를 잘라본다
    for (int i = 0; i < N; i++)
        if (tree[i] - height > 0)
            len = len + tree[i] - height;

    //조건 충족
    if (len >= M)
        return true;
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    long long low = 1, high = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];

        high = max(high, tree[i]);
    }

    long long result = 0;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (possible(mid))
        {
            result = max(result, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << result << "\n";
    return 0;
}
