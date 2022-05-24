#include <string>
#include <vector>
#include <iostream>
#include <cstring>


using namespace std;


int n_sum(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + n_sum(n - 1);
    }
}


vector<int> solution(int n) {
    vector<int> answer;

    //Get the largest number according to n

    int total = n_sum(n);
    /*
        for(int i=1; i<=n; i++){
            total += i;
        }
    */
    //init arr -> 0
    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    //second index = 2 (Do +1 each time index goes up)
    int number = 2, i = 0, j = 0;

    // first index = 1
    arr[i][j] = 1;

    bool flag = false;

loop:while (number <= total) {

    if (flag == true) {
        break;
    }


    //fill lengthwise
    while (flag == false) {
        //The first condition is braked by the second condition after the first application only.
        if (i + 1 >= n || arr[i + 1][j] != 0) {
            break;
        }
        arr[i + 1][j] = number;
        i++;
        number++;
        if (number > total) {
            flag = true;
            goto loop;
        }
    }

    //fill horizontal
    while (flag == false) {
        //The first condition is braked by the second condition after the first application only.
        if (j + 1 >= n || arr[i][j + 1] != 0) {
            break;
        }
        arr[i][j + 1] = number;
        j++;
        number++;
        if (number > total) {
            flag = true;
            goto loop;
        }
    }

    //fill diagonal
    while (flag == false) {
        //The first condition is braked by the second condition after the first application only.
        if (i - 1 < 0 || j - 1 < 0 || arr[i - 1][j - 1] != 0) {
            break;
        }
        arr[i - 1][j - 1] = number;
        i--;
        j--;
        number++;
        if (number > total) {
            flag = true;
            goto loop;
        }
    }
    //OST : break;
}

for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
        answer.push_back(arr[i][j]);
    }
}
return answer;
}

int main() {
    int n = 5;
    vector<int> d;
    d = solution(n);
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << ",";
    }
}