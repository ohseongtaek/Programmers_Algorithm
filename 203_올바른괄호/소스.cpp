#include<string>
#include <iostream>
#include <stack>

using namespace std;
/*
bool solution(string s)
{
   // bool answer = false;
    int temp = 0;
    int k = s.length();

    if (s[0] == ')' || s[k-1] == '(') {
        return false;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            temp++;
        }
        else {
            temp--;
            if (temp < 0) {
                return false;
            }
        }
    }
    if (temp == 0) {
        return true;
    }
}
*/
bool solution(string s)
{
    //bool answer = true;
    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else {
            if (st.empty()) {
                return false;
            }
            else {
                st.pop();
            }
        }
    }
    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }

}


int main() {
    string str = "(()(";
    bool dab;

    dab = solution(str);

    cout << dab;
}