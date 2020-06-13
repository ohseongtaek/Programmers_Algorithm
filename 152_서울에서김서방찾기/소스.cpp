#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string temp = "Kim";
    int k;
    for (int i = 0; i < seoul.size(); i++) {
        if (temp == seoul[i]) {
            k = i;
            answer = "김서방은 " + to_string(k) + "에 있다";
            break;
        }
    }
    return answer;
}