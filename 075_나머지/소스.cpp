#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {};
    int arr2[10] = {};
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < 10; j++) {
        arr2[j] = arr[j] % 42;
    }


    return 0;
}