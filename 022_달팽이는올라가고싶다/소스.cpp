#include <iostream>

using namespace std;

int main()
{
    int a, b, v;
    int tempday;
    cin >> a >> b >> v;

    tempday = (v - b - 1) / (a - b) + 1;
    cout << tempday;

    return 0;
}