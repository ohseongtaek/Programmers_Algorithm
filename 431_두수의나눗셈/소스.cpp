#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;

    float test = ((float)num1 / (float)num2) * 1000;

    answer = test;

    return answer;
}