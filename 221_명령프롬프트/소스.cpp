#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase;
    cin >> testcase;
    string str;
    vector<string> v;

    for (int i = 0; i < testcase; i++) {
        cin >> str;
        v.push_back(str);
    }

    //cout << v.size();

    string dab = "";

    for (int i = 0; i < v[0].length(); i++) {
        char c = v[0][i];

        for (int j = 0; j < v.size(); j++) {
            if (c != v[j][i]) {
                c = '?';
                break;
            }
            else {
                continue;
            }
        }
        dab += c;
    }
    cout << dab << endl;
}