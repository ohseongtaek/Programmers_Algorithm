#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v = {
    "........",
    "........",
    "........",
    "........",
    "........",
    "........",
    "........",
    "........"
};



int main() {
    vector<string> str;
    string str1;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        cin >> str1;
        str.push_back(str1);
    }
    for (int i = 0; i < str.size(); i++) {
        if (i == 0 || i % 2 == 0) {
            for (int j = 0; j < 8; j = j + 2) {
                if (v[i][j] != str[i][j]) {
                    count++;
                }
            }
        }
        else {
            for (int j = 1; j < 8; j = j + 2) {
                if (v[i][j] != str[i][j]) {
                    count++;
                }
            }

        }
    }
    cout << count << endl;
}