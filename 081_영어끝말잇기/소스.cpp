#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool fail = false;
    for (int i = 1; i < words.size(); i++) {
        string first = words[i - 1];
        string second_OR_diff = words[i];

        for (int j = 0; j < i; j++) {
            if (second_OR_diff == words[j]) {
                fail = true;
                break;
            }
        }

        int first_len = first.length();

        if (first[first_len - 1] != second_OR_diff[0]) {
            fail = true;
        }

        if (fail) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        if (fail == false && i == words.size() - 1) {
            answer.push_back(0);
            answer.push_back(0);
        }

    }
    return answer;
}