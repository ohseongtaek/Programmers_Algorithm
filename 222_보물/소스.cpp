#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool ost(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase, temp;
    cin >> testcase;

    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < testcase; i++) {
        cin >> temp;
        v1.push_back(temp);
    }
    for (int i = 0; i < testcase; i++) {
        cin >> temp;
        v2.push_back(temp);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), ost);

    int sum = 0;

    for (int i = 0; i < testcase; i++) {
        sum += v1[i] * v2[i];
    }
    cout << sum << endl;
}