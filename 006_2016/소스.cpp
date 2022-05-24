#include <string>
#include <vector>
using namespace std;
string arr[] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };

string solution(int a, int b) {
    string answer = "";
    int date[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0;
    for (int i = 0; i < a - 1; i++) {
        sum = sum + date[i];
    }
    sum = sum + b;
    answer = arr[sum % 7];

    return answer;

}