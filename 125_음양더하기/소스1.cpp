#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    if (absolutes.size() != signs.size()) {
        cout << " Vector Size is Different" << endl;
        return 0;
    }

    for (int i = 0; i < absolutes.size(); i++) {
        if (signs[i] == true) {
            absolutes[i] = abs(absolutes[i]);
        }
        else {
            absolutes[i] = -absolutes[i];
        }

        answer += absolutes[i];

    }

    return answer;
}

int main() {

    vector<int> temp = { 4,7,12 };
    vector<bool> sign = { true,false,true };

    cout << solution(temp, sign) << endl;

}