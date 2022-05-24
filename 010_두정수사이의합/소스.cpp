#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    //cout << "what?" << endl;
    if (a > b) {
        //cout << "what2" << endl;
        while (a >= b) {
            answer = answer + b;
            b++;
        }
    }
    else if (a < b) {
        //cout << "what3" << endl;
        while (a <= b) {
            answer = answer + a;
            a++;
        }
    }
    else {
        answer = a;
    }
    return answer;
}