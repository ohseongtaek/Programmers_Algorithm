#include <string>
#include <vector>

using namespace std;

string s = "수";
string b = "박";
string sb = "수박";
string solution(int n) {
    string answer = "";
    /*
    if (n == 1) {
        answer = s;
        return answer;
    }
    */
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            answer = answer + sb;
        }
        return answer;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                answer = answer + s;
            }
            else if (i % 2 == 1) {
                answer = answer + b;
            }
            else {
                answer = answer + s;
            }
        }
        return answer;
    }
}