#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int want;
    cin >> want;

    int count = 0;
    while (want != 0) {
        if (want % 2 == 1) {
            count++;
        }
        want /= 2;
    }
    cout << count << '\n';

}
