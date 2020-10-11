#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<char> a;
    vector<int> b;
    vector<pair<char, int>> vp;

    //priority_queue<int, vector<int>> pq;
    deque<int> dq;

    for (int i = 0; i < operations.size(); i++) {
        for (int j = 0; j < operations[i].size(); j++) {
            if (operations[i][j] == ' ') {
                continue;
            }
            else if (operations[i][j] == 'I' || operations[i][j] == 'D') {
                a.push_back(operations[i][j]);
            }
            else {
                string temp = operations[i].substr(j, operations[i].size() - 1);
                b.push_back(stoi(temp));
                break;
            }
        }
    }
    /* Test code
    for(int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
    cout << endl;
    for(int j=0; j<b.size(); j++){
        cout << b[j] << endl;
    }
    */

    for (int i = 0; i < a.size(); i++) {
        vp.push_back(make_pair(a[i], b[i]));

    }

    /* Test code
    for(int i=0; i<a.size(); i++){
        cout << vp[i].first << " " << vp[i].second << endl;
    }
    */

    for (int i = 0; i < vp.size(); i++) {
        sort(dq.begin(), dq.end());
        if (vp[i].first == 'I') {
            dq.push_front(vp[i].second);
        }
        else if (vp[i].first == 'D') {
            if (dq.empty()) {
                continue;
            }
            else if (vp[i].second == -1) {
                dq.pop_front();
            }
            else if (vp[i].second == 1) {
                dq.pop_back();
            }
        }
    }
    sort(dq.begin(), dq.end());

    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq[dq.size() - 1]);
        answer.push_back(dq[0]);
    }


    return answer;
}