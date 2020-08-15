#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
vector<string> ALL;

bool comp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

void ALL_nCr(int yul, int temp = 0, string str = "") {
    for (int i = temp; i < yul; i++) {
        str += to_string(i);
        ALL.push_back(str);
        ALL_nCr(yul, i + 1, str);
        //cout << str << endl;
        str = str.substr(0, str.length() - 1);
    }

}

bool second_key(vector<vector<string>> relation, string comp2) {
    map<string, int> Check;
    for (int i = 0; i < relation.size(); i++) {
        string temp = "";
        for (int j = 0; j < comp2.length(); j++) {
            int num = comp2[j] - '0';
            temp = temp + relation[i][num] + " ";
        }
        temp = temp.substr(0, temp.length() - 1);
        if (Check[temp]) {
            return false;
        }
        Check[temp]++;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int hang_size = relation.size();
    int yul_size = relation[0].size();

    ALL_nCr(yul_size);

    sort(ALL.begin(), ALL.end(), comp);

    /*  debug code
    for (int i = 0; i < ALL.size(); i++) {
        cout << ALL[i] << endl;
    }
    */

    for (int i = 0; i < ALL.size(); i++) {
        if (second_key(relation, ALL[i])) {
            string temp = ALL[i];
            for (int j = ALL.size() - 1; j >= i; j--) {
                bool block = true;

                for (auto x : temp) {
                    if (ALL[j].find(x) == string::npos) {
                        block = false;
                        break;
                    }
                }
                if (block) {
                    ALL.erase(ALL.begin() + j);
                }
            }
            i--;
            answer++;
        }
    }
    return answer;
}


int main() {
    vector<vector<string>> v = {
        {"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
        {"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
        {"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };
    cout << solution(v) << endl;
}