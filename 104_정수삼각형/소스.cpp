#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    //cout << "one  " << first_size << endl;     //4
    //cout << "two  " << second_size << endl;    //5



    for (int i = triangle.size() - 1; i >= 0; i--) {
        if (i == 0) {
            answer = triangle[i][0];
            break;
        }

        for (int j = 0; j < triangle[i].size() - 1; j++) {
            int temp = max(triangle[i][j], triangle[i][j + 1]);
            //cout << "best temp " << i << " < i value " << temp << endl;

            triangle[i - 1][j] += temp;

            //cout << triangle[i-1][j]  <<endl;

        }
    }

    return answer;
}