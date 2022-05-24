#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805;
int solution(int m, int n, vector<vector<int>> city_map) {

    // right case
    int right[501][501];
    // down case
    int down[501][501];

    // start 1,1 and finish m,n
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // init first value
            if (i == 1 && j == 1) {
                right[i][j] = 1;
                down[i][j] = 1;

                //if(city_map[0][0] != 0)   Error of Problem
                continue;
            }

            // right + down case
            // Last index of city_map Must be 0
            if (city_map[i - 1][j - 1] == 0) {
                right[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
                down[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
            }

            // Not use road case
            else if (city_map[i - 1][j - 1] == 1) {
                right[i][j] = 0;
                down[i][j] = 0;
            }

            // only Straight right and down case
            else if (city_map[i - 1][j - 1] == 2) {
                right[i][j] = right[i][j - 1];
                down[i][j] = down[i - 1][j];
            }
        }
    }
    /* debug code
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout << right[i][j] << " " << down[i][j] << "       ";
        }
        cout << endl;
    }
    */

    return right[m][n];
}

int main() {
    int m = 3;
    int n = 6;
    vector<vector<int>> v = { {0, 2, 0, 0, 0, 2},
                             {0, 0, 2, 0, 1, 0},
                             {1, 0, 0, 2, 2, 0} };
    int d = solution(m, n, v);
    cout << d << endl;
}