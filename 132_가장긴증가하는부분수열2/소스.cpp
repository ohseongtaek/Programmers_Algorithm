#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    int N, temp, cnt = 0;
    
    cin >> N;
    v.clear();
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (v.empty()) {
            v.push_back(temp);
        }
        else if (temp > v.back()) {
            v.push_back(temp);
        }
        else {
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
            *low = temp;
        }
    }
    cout << v.size();
    return 0;
}
