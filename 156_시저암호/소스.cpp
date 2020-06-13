#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 32) {
            answer.push_back(s[i]);
        }
        else if (90 < s[i] + n && s[i] < 91) {
            answer.push_back(s[i] + n - 26);
        }
        else if (122 < s[i] + n && 96 < s[i]) {
            answer.push_back(s[i] + n - 26);
        }
        else {
            answer.push_back(s[i] + n);
        }
    }
    return answer;
}