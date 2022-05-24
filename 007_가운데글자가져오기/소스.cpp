#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string arr[101];
    for (int i = 0; i < s.length(); i++) {
        arr[i] = s[i];
    }
    if (s.length() % 2 == 0) {
        answer = arr[s.length() / 2 - 1] + arr[s.length() / 2];
    }

    if (s.length() % 2 == 1) {
        answer = arr[s.length() / 2];
    }

    return answer;
}