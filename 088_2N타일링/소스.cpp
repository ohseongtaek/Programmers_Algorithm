#include <string>
#include <iostream>
#include <vector>
#define NANUM 1000000007
int arr[600001];
using namespace std;

int solution(int n) {
    int answer = 0;

    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % NANUM;
    }
    answer = arr[n];
    return answer;
}