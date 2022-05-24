#include <string>
#include <vector>
#include<iostream>
#include <sstream>
using namespace std;

string solution(string s) {
    /* error code 공백이 여러개일 경우 그만큼 공백으로 표시해야한다는 조건을 체크하지 않았다....
    vector<string> strv;
    string st;
    for (stringstream sts(s); (sts >> st);) {
        strv.push_back(st);
    }
    for (int i = 0; i < strv.size(); i++) {
        int k = 1;
        if (strv[i][0] >= 48 && strv[i][0] <= 57) {
            if (strv[i][1] <= 122 && strv[i][1] >= 97) {
                strv[i][1] = strv[i][1] - 32;
            }
            k = 2;
        }
        if (97 <= strv[i][0] && strv[i][0] <= 122) {
            strv[i][0] = strv[i][0] - 32;
            //cout << strv[i][0] << endl;
        }
        for (int j = k; j < strv[i].size(); j++) {
            if (strv[i][j] >= 65 && strv[i][j] <= 90) {
                strv[i][j] = strv[i][j] + 32;
            }
        }
        answer = answer + strv[i];
        if (i != strv.size()-1) {
            answer = answer + " ";
        }
    }
    */
    int first_string = 0;

    for (int i = 0; i < s.size(); i++) {
        if (first_string == 0) {
            s[i] = toupper(s[i]);
            first_string = 1;
        }
        else {
            s[i] = tolower(s[i]);
        }
        if (s[i] == ' ') {
            first_string = 0;
        }
    }


    return s;
}

int main() {
    string str = "3for 2the    last week";

    cout << solution(str);
}
