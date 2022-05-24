#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int arr[101][101];

    // init arr index 0
    memset(arr, 0, sizeof(arr));

    // init n,m index init 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = 1;
            //cout << i << "  " << j << "   =" << arr[i][j] << ", ";
        }
        //cout << endl;
    }

    // puddles -> set 0
    for (int i = 0; i < puddles.size(); i++) {
        int hang = puddles[i][1];
        int yul = puddles[i][0];
        arr[hang][yul] = 0;

        //If there are puddles on the top and left, set to zero after that.
        if (hang == 1 || yul == 1) {
            if (hang == 1) {
                //                cout <<"good1" << endl;
                for (int j = yul; j <= m; j++) {
                    arr[hang][j] = 0;
                }
            }
            else {
                //                cout <<"good2" << endl;
                for (int j = hang; j <= n; j++) {
                    arr[j][yul] = 0;
                }
            }
        }

    }

    // calculation of the number of cases (!!! mod 1000000007 !!!)
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (arr[i][j] != 0) {
                arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
            }
        }
    }

    /* debug code
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            //arr[i][j] = 1;
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }
    */

    // input answer
    answer = arr[n][m];

    return answer;
}

int main() {
    int m = 5;
    int n = 5;
    vector<vector<int>> v = { {1,3},{3,2} };
    int d = solution(m, n, v);
    cout << d << endl;
}