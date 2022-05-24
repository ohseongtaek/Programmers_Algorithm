#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i] % divisor;
        if (num == 0) {
            answer.push_back(arr[i]);
            count++;
        }
    }
    if (count == 0) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());

    return answer;
}