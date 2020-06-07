#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    char c;
    int sum = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        sum = sum + (c - '0');
    }
    cout << sum;
}