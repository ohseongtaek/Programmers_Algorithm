#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    string strt;
    int n;
    cin >> str >> n;
    for (int i = 0; i < n; i++)
    {
        strt += str;
    }
    cout << strt;
    return 0;
}