#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    int str_sub = 0;
    int temp = 0;
    vector<int> v;
    vector<char> oper;


    // oper count and push_back
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            oper.push_back(expression[i]);
        }
    }



    // number count and push_back
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            v.push_back(stoi(expression.substr(str_sub, temp)));
            str_sub = i + 1;
            temp = 0;
        }
        temp++;
    }
    v.push_back(stoi(expression.substr(str_sub, temp)));

    
    cout << v[0] + (oper[0] -'0') + v[1];

    return answer;
    
}

int main() {
    string str = "100-200*300-500+20";
    long long dab;

    dab = solution(str);

    cout << dab;
}