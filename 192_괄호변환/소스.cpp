#include <string>
#include <vector>

using namespace std;

bool ost(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            sum++;
        }
        else if (s[i] == ')') {
            sum--;
        }
        if (sum < 0) {
            return false;
        }
    }
    return true;
}

string ost2(string t) {
    string u, v;
    if (t == "") {
        return "";
    }
    else {

        int Left = 0;
        int Right = 0;

        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '(') {
                Left++;
            }
            else if (t[i] == ')') {
                Right++;
            }
            if (Left == Right) {
                u = t.substr(0, i + 1);
                v = t.substr(i + 1);
                break;
            }
        }
    }
    if (ost(u)) {
        return u + ost2(v);
    }
    else {
        string temp = "(" + ost2(v) + ")";
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') {
                temp = temp + ')';
            }
            else {
                temp = temp + '(';
            }
        }
        return temp;
    }
}


string solution(string p) {
    return ost2(p);
}