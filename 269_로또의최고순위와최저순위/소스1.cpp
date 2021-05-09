#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum Matching {
    FIRST_PLACE = 1,
    SECOND_PLACE,
    THIRD_PLACE,
    FOUR_PLACE,
    FIVE_PLACE,
    FAIL
};

void Matching_Rank(vector<int>& ans, int win, int lost, bool bRtn) {

    if (bRtn) {
        int above = win + lost;
        switch (above) {
        case 6: ans.push_back(FIRST_PLACE);
            break;
        case 5: ans.push_back(SECOND_PLACE);
            break;
        case 4: ans.push_back(THIRD_PLACE);
            break;
        case 3: ans.push_back(FOUR_PLACE);
            break;
        case 2: ans.push_back(FIVE_PLACE);
            break;
        default: ans.push_back(FAIL);
            break;
        }
    }
    else {
        int below = win;
        switch (below) {
        case 6: ans.push_back(FIRST_PLACE);
            break;
        case 5: ans.push_back(SECOND_PLACE);
            break;
        case 4: ans.push_back(THIRD_PLACE);
            break;
        case 3: ans.push_back(FOUR_PLACE);
            break;
        case 2: ans.push_back(FIVE_PLACE);
            break;
        default: ans.push_back(FAIL);
            break;
        }
    }
}


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int win = 0;
    int lost = 0;
    for (int i = 0; i < lottos.size(); i++) {

        int diff = lottos[i];

        if (lottos[i] == 0) {
            lost++;
            continue;
        }

        for (int j = 0; j < win_nums.size(); j++) {
            if (diff == win_nums[j]) {
                win++;
            }
        }
    }

    Matching_Rank(answer, win, lost, true);
    Matching_Rank(answer, win, lost, false);


    return answer;
}

int main() {

    vector<int> pick = { 0,0,0,0,0,0 };
    vector<int> tv = { 38, 19, 20, 40, 15, 25 };

    vector<int> DAB = solution(pick, tv);

    for (int i = 0; i < DAB.size(); i++) {
        cout << DAB[i] << endl;
    }

    /*
    lottos	win_nums	result
    [44, 1, 0, 0, 31, 25]	[31, 10, 45, 1, 6, 19]	[3, 5]
    [0, 0, 0, 0, 0, 0]	[38, 19, 20, 40, 15, 25]	[1, 6]
    [45, 4, 35, 20, 3, 9]	[20, 9, 3, 45, 4, 35]	[1, 1]

    1	6개 번호가 모두 일치
    2	5개 번호가 일치
    3	4개 번호가 일치
    4	3개 번호가 일치
    5	2개 번호가 일치
    6(낙첨)	그 외
    */
}