#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<char, string>> vp;
vector<pair<char, string>>::iterator iter;
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    for (int i = 0; i < strings.size(); i++) {
        vp.push_back(make_pair(strings[i][n], strings[i]));
    }

    sort(vp.begin(), vp.end());


    for (int i = 0; i < strings.size(); i++) {
        answer.push_back(vp[i].second);
    }
    return answer;
}