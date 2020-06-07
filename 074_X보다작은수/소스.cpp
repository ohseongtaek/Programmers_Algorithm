#include <iostream>
using namespace std;
int main()
{
    int n, x, e;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        if (e < x)
        {
            cout << e << " ";
        }
    }
    cout << endl;
}