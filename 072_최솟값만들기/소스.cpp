#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    /*for (int i = 0; i < B.size(); i++) {
        cout << B[i] << endl;                   debug code
    }*/
    for (int i = 0; i < B.size(); i++) {
        answer += A[i] * B[i];
    }
    return answer;
}