#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> v;

long long cmp(long long x, long long y) {
    return x > y;
}

long long solution(long long n) {
    long long answer = 0;
    long long temp = 0;
    while (n != 0) {
        v.push_back(n % 10);
        n = n / 10;
        temp++;
    }

    sort(v.begin(), v.end(), cmp);

    long long gob = pow(10, temp - 1);

    for (int i = 0; i < v.size(); i++) {
        answer += v[i] * gob;
        gob = gob / 10;
    }

    return answer;
}