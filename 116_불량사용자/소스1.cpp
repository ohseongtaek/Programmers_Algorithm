#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

vector<int> v_idx[8];
int visit[8];
set<string> s;

void dfs(int idx, int N) {

    if (idx == N) {
        string tmp = "";
        for (int i = 0; i < 10; i++)
            if (visit[i] == 1) tmp += to_string(i);
        s.insert(tmp);
        return;
    }

    for (int j = 0; j < v_idx[idx].size(); j++) {
        int value = v_idx[idx][j];

        if (visit[value] == 1) {
            continue;
        }
        visit[value] = 1;

        // re call
        dfs(idx + 1, N);

        visit[value] = 0;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    // 각 밴 아이디에 따른 가능한 유저아이디의 index 값을 벡터에 넣는다
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            bool flag = true;
            if (banned_id[i].length() == user_id[j].length()) {
                for (int k = 0; k < banned_id[i].size(); k++) {
                    if (banned_id[i][k] != user_id[j][k]) {
                        if (banned_id[i][k] == '*') {
                            continue;
                        }
                        flag = false;
                    }
                }
            }
            else {
                continue;
            }
            if (flag) {
                v_idx[i].push_back(j);
            }
        }
    }

    /* debug code
    for(int i=0; i< 8; i++){
        for(int j=0; j<v_idx[i].size(); j++){
            cout << "i = " << i << " vidx = " << v_idx[i][j] << endl;
        }
    }
    */

    dfs(0, banned_id.size());
    answer = s.size();


    return answer;
}
/*
i = 0 vidx = 0
i = 0 vidx = 1
i = 1 vidx = 0
i = 1 vidx = 2
i = 2 vidx = 3
i = 2 vidx = 4
i = 3 vidx = 3
i = 3 vidx = 4


i = 0  value = fr*d* frodo
i = 0  value = fr*d* fradi

i = 1  value = *rodo frodo
i = 1  value = *rodo crodo

i = 2  value = ****** abc123
i = 2  value = ****** frodoc

i = 3  value = ****** abc123
i = 3  value = ****** frodoc
*/

int main() {

    vector<string> u = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> b = { "fr*d*", "*rodo", "******","******" };
    int a = solution(u, b);
    cout << a << endl;
    return 0;

}