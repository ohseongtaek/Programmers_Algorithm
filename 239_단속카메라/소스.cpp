#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 1; // basic have one camera

    // sort routes !!
    sort(routes.begin(), routes.end());

    // first car exit time == temp
    int temp = routes[0][1];

    for (int i = 1; i < routes.size(); i++) {

        // If The rear car comes in later than the front car leaves
        if (routes[i][0] > temp) {
            answer++;
            temp = routes[i][1];
        }

        // If the car ahead arrives later than the car behind
        if (temp >= routes[i][1]) {
            temp = routes[i][1];
        }

        /* this is error code
        if(temp >= routes[i][0] && temp <= routes[i][1]){
            temp = routes[i][1];
            continue;
        }
        else{
            answer++;
        }
        */
    }
    return answer;
}

int main() {
    vector<vector<int>> v = { {3,5},{4,6} };
    cout << "solution ? " << solution(v) << endl;
    cout << endl;
}