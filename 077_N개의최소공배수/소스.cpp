#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd_is_gop(int a, int b) {
    //cout << a << " " << b << endl;
    int n;
    int a_temp = a;
    int b_temp = b;
    int temp;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    temp = (a_temp * b_temp) / a;
    return temp;
}

int solution(vector<int> arr) {
    int answer = 0;

    for (int i = 1; i < arr.size(); i++) {

        arr[i] = gcd_is_gop(arr[i - 1], arr[i]);
        //cout << arr[i] << endl;
    }
    answer = arr[arr.size() - 1];
    return answer;
}

int main() {
    vector<int> arr = { 2,6,8,14 };
    int dab;
    dab = solution(arr);
    cout << dab;
}
