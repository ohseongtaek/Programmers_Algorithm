#include <iostream>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

deque <int> dq;
char arr[400005];

int main() {

    int t;
    cin >> t;

    while (t--) {

        memset(arr, '\0', sizeof(arr));
        bool e = false;
        bool r = false;
        dq.clear();
        string p; int n;
        cin >> p >> n >> arr;

        char* tmp = strtok(arr, "[,]");
        while (tmp) {
            dq.push_back(stoi(tmp));
            tmp = strtok(NULL, "[,]");
        }

        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                if (r) r = false;
                else r = true;
            }
            if (p[i] == 'D') {
                if (dq.empty()) {
                    e = true;
                    break;
                }
                if (r) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (e) cout << "error\n";
        else {
            cout << '[';
            for (int i = 0; i < dq.size(); i++) {
                if (r) cout << dq[dq.size() - 1 - i];
                else cout << dq[i];

                if (i == dq.size() - 1) continue;
                else cout << ',';
            }
            cout << "]\n";
        }
    }
    return 0;
}