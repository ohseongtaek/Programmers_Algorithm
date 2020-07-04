#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int pick_poketmon = nums.size() / 2;
    vector<int> temp;

    for (int i = 0; i < nums.size(); i++) {
        temp.push_back(nums[i]);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
    if (pick_poketmon <= temp.size()) {
        answer = pick_poketmon;
    }
    else {
        answer = temp.size();
    }

    return answer;
}

int main() {
    vector<int> num = { 1, 200, 200, 1, 1, 1, 100, 100 };

    cout << solution(num);
}