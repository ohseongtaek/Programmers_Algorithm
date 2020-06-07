#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        for (int t = 1; t <= i - 1; t++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * num - (i - 1) * 2 - 1; j++)
        {
            cout << "*";
        }

        cout << '\n';
    }

    for (int i = 2; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << '\n';
    }
}