#include <string>
#include <vector>

using namespace std;

char arr[9];

bool solution(string s) {
    bool answer = true;
    for (int i = 0; i < s.length(); i++) {
        arr[i] = s[i];
    }
    if (s.length() == 4 || s.length() == 6) {

        for (int i = 0; i < s.length(); i++) {
            if (arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' ||
                arr[i] == '7' || arr[i] == '8' || arr[i] == '9' || arr[i] == '0') {
                answer = true;
            }
            else {
                answer = false;
                break;
            }
        }
    }
    else {
        answer = false;
    }
    return answer;
}