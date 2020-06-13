#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long temp = 0;
    bool x = true;
    while (temp < n) {
        temp++;
        if (pow(temp, 2) == n) {
            answer = pow(temp + 1, 2);
            x = false;
            break;
        }
        else {
            answer = -1;
        }
    }
    return answer;
}