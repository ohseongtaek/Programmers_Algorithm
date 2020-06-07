#include <iostream>
using namespace std;
int main()
{
    int arr[10] = { 0 };
    int a, b, c, sum, na;
    cin >> a;
    cin >> b;
    cin >> c;

    sum = a * b * c;

    while (sum > 0) {
        na = sum % 10;
        sum = sum / 10;
        arr[na]++;
    }


    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }



    return 0;
}