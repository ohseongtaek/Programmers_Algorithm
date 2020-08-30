#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 9;


void refunc(int n, int number, int cnt, int Current_Number) {
    if (cnt > 8) {
        return;
    }
    if (Current_Number == number) {
        answer = min(answer, cnt);
    }

    int temp_number = 0;

    for (int i = 0; i < 8; i++) {
        temp_number = temp_number * 10 + n;
        refunc(n, number, cnt + 1 + i, Current_Number + temp_number);
        refunc(n, number, cnt + 1 + i, Current_Number - temp_number);
        refunc(n, number, cnt + 1 + i, Current_Number * temp_number);
        refunc(n, number, cnt + 1 + i, Current_Number / temp_number);
    }
}


int solution(int N, int number) {

    refunc(N, number, 0, 0);

    if (answer > 8) {
        answer = -1;
    }

    return answer;

}

int main() {
    int n = 5;
    int num = 12;
    cout << solution(n, num) << endl;;

}