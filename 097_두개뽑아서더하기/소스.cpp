#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end());

    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    /*
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    */

    cout << endl;

    return answer;
}

int main() {
    vector<int> n = { 2,1,3,4,1 };
    vector<int> d;
    d = solution(n);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << endl;
    }
}