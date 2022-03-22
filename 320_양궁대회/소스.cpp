#include <string>
#include <iostream>
#include <vector>

#define LAST_IDX 11

using namespace std;

vector<int> answer(1, -1);  // 기본 비기는경우거나 지는경우에는 -1 리턴 
int diff_score_max = 0;

// 아래 점수에 스코어가 많은지 찾는 함수 
bool find_low_score(vector<int> &win) 
{
    for (int i = 10; i >= 0; i--) 
    {
        if (win[i] > answer[i])
        {
            return true;
        }
        else if (win[i] < answer[i])
        {
            return false;
        }
    }
}

// 점수 차이 계산 함수 
void cal_score(vector<int>& win, vector<int>& lose)
{
    int win_ryan_score = 0;
    int lose_apeach_score = 0;
    int diff_score = 0;
    // 각 스코어 점수 계산
    for (int i = 0; i < LAST_IDX; i++)
    {
        if (win[i] > lose[i])
        {
            win_ryan_score += 10 - i;
        }
        else if (lose[i] > 0)
        {
            lose_apeach_score += 10 - i;
        }
    }
    
    // 각 점수 차이 계산 
    diff_score = win_ryan_score - lose_apeach_score;
    
    if (diff_score > 0 && diff_score >= diff_score_max)
    {
        if ((diff_score_max == diff_score) && (false == find_low_score(win)))
        {
            return;
        }
        // 최대 점수를 저장하고 벡터 삽입 
        diff_score_max = diff_score;
        answer = win;
    }
}

// 완전탐색 
void all_case(int index, int arrows, vector<int> &win, vector<int> &lose)
{
    // index 가 마지막이거나 화살이 없는 경우 
    if (index == LAST_IDX || arrows == 0)
    {
        // 남은 화살이 있던 없던 마지막 인덱스에 도착한경우에 0점에 모두 쏴버리기
        win[10] += arrows;
        cal_score(win, lose);
        // 점수 계산 후 다시 재귀함수를 돌리기위해 원래대로 초기화 
        win[10] -= arrows;
        return;
    }

    // 점수 획득하는 경우 
    if (lose[index] < arrows)
    {
        int use_arrows = lose[index] + 1;
        // 어피치 보다 1발 더 쏘면 점수 획득함 
        win[index] += use_arrows;
        // 인덱스 하나 올려주고 화살수는 위에서 한만큼 빼주기 
        all_case(index + 1, arrows - use_arrows, win, lose);
        // 위의 케이스가 끝나면 원래대로 돌려주기 
        win[index] -= use_arrows;
    }

    // 점수를 얻지 않는 경우 혹은 현재 인덱스에서 얻을수있는 점수를 모두 획득한 후 다음 인덱스 점수를 획득하기 위한 경우 
    all_case(index + 1, arrows, win, lose);
}

vector<int> solution(int n, vector<int> info) 
{
    // 벡터 초기화 0으로 11개 사이즈
    vector<int> win(11, 0);

    // index = 0 (0부터 하나씩 라이언보다 높게 쏜 전체 결과를 얻기위해 index 필요)
    // n = 화살수
    // win = 라이언의 벡터 
    // info = 어피치의 벡터 
    all_case(0, n, win, info);

    // 결과 리턴 
    return answer;
}
int main()
{
    vector<int> a = { 5,1,9,10 };
    vector<vector<int>> aa = { {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                               {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3} };

    for (int i = 0; i < a.size(); i++)
    {
        vector<int> dab = solution(a[i], aa[i]);
        cout << " i ";
        for (int j = 0; j < dab.size(); j++)
        {
            cout << dab[j] << " ";
        }
        cout << endl;
    }

    /*[0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0]
    [-1]
    [1, 1, 2, 0, 1, 2, 2, 0, 0, 0, 0]
    [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2]*/
}
