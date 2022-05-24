#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int one[5] = { 1, 2, 3, 4, 5 };
int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int the[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % 5]) count1++;
        if (answers[i] == two[i % 8]) count2++;
        if (answers[i] == the[i % 10]) count3++;
    }
    int temp = max(max(count1, count2), count3);

    if (temp == count1) answer.push_back(1);
    if (temp == count2) answer.push_back(2);
    if (temp == count3) answer.push_back(3);

    return answer;
}