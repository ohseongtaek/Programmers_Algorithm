
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> str;
vector<char> tt;
int main(void)
{
    int a;
    cin >> a;
    bool loop = true;
    string temp;
    for (int i = 0; i < a; i++) {
        cin >> temp;
        str.push_back(temp);
    }

    for (int i = 0; i < str.size(); i++) {
        int count = 1;
        char ost = str[i][0];

        for (int j = i + 1; j < str.size(); j++) {
            for (int k = 0; k < tt.size(); k++) {
                if (ost == tt[k]) {
                    loop = false;
                }
            }
            if (loop == true) {
                if (ost == str[j][0]) {
                    count++;
                }
            }
        }
        if (count >= 5) {
            tt.push_back(ost);
        }
        loop = true;
    }

    sort(tt.begin(), tt.end());

    if (tt.size() == 0) {
        cout << "PREDAJA";
    }
    else {
        for (int i = 0; i < tt.size(); i++) {
            cout << tt[i];
        }
    }

    return 0;
}


/*
Case !!!
5
zabc
zadsf
zafds
zfdas
zasdf
*/