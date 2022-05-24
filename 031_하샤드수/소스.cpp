#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = 0;
    int tem = x;
    while (x != 0) {
        temp = temp + (x % 10);
        x = x / 10;
    }
    if (tem % temp == 0) {
        answer = true;
    }
    else {
        answer = false;
    }
    return answer;
}