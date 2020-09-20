#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    // * -> 10
    // 0 -> 11
    // # -> 12
    int left_postion = 10;
    int right_postion = 12;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            left_postion = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            right_postion = numbers[i];
        }
        else {
            if (numbers[i] == 0) {
                numbers[i] = 11;
            }

            int left = abs(numbers[i] - left_postion);
            int right = abs(numbers[i] - right_postion);

            int left_Dist = (left / 3) + (left % 3);
            int right_Dist = (right / 3) + (right % 3);

            if (left_Dist == right_Dist) {
                if (hand == "right") {
                    answer += 'R';
                    right_postion = numbers[i];
                }
                else {
                    answer += 'L';
                    left_postion = numbers[i];
                }
            }
            else {
                if (left_Dist < right_Dist) {
                    answer += 'L';
                    left_postion = numbers[i];
                }
                else {
                    answer += 'R';
                    right_postion = numbers[i];
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<int> n = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string h = "right";
    cout << solution(n, h) << endl;
}