#include<iostream>

using namespace std;

int arr[100];

int gcd(int a, int b) {

    int n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;

}

int main() {
    int T;
    cin >> T;
    cin >> arr[0];
    int temp;
    for (int i = 1; i < T; i++) {
        cin >> arr[i];
        temp = gcd(arr[0], arr[i]);
        cout << arr[0] / temp << "/" << arr[i] / temp << endl;
    }
}