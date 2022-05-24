#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool sosu(int sum) {
    if (sum == 0 || sum == 1) {
        false;
    }

    int temp = 0;
    int oper = 0;

    while (sum != oper) {
        oper++;
        int k = sum % oper;
        if (k == 0) {
            temp++;
        }
    }
    if (temp == 2) {
        return true;
    }
    else {
        return false;
    }
}
int solution(vector<int> nums) {

    int answer = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sosu(sum)) {
                    answer++;
                }

            }
        }
    }
    return answer;
}