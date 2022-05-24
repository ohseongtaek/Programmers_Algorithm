#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int x, int y) {
    return x > y;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int vmin = 9999;
    for (int i = 0; i < arr.size(); i++) {
        vmin = min(vmin, arr[i]);
    }

    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    else {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == vmin) {
                continue;
            }
            answer.push_back(arr[i]);
        }
    }
    return answer;
}