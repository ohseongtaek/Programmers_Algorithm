#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> what;
    for (int i = 0; i < commands.size(); i++) {
        what.clear();
        int num, num2;
        num = commands[i][0];
        num2 = commands[i][1];

        for (int j = num; j <= num2; j++) {
            what.push_back(array[j - 1]);
        }

        sort(what.begin(), what.end());

        int ost = commands[i][2];
        answer.push_back(what[ost - 1]);
    }
    return answer;
}