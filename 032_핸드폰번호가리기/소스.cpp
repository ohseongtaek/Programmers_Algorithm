#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int temp = phone_number.size();

    for (int i = 0; i < temp - 4; i++) {
        phone_number[i] = '*';
    }

    answer = phone_number;

    return answer;
}