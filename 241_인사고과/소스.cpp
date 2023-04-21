#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct hinfo 
{
    int at;
    int score;
    int idx;
};

bool comp(hinfo a, hinfo b)
{
    return a.at > b.at;
}

bool comp2(pair<int, int> a, pair<int, int> b) 
{
    if (a.first == b.first)
    {
        return b.second < a.second;
    }
    else
    {
        return a.first > b.first;
    }
}

int solution(vector<vector<int>> scores) 
{
    vector<hinfo> v;
    vector<pair<int, int>> vp;

    for (int i = 0; i < scores.size(); i++)
    {
        hinfo in;
        in.at = scores[i][0];
        in.score = scores[i][1];
        in.idx = i;
        v.push_back(in);
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) 
    {
        bool flag = true; 
        hinfo r = v[i];
        for (int j = 0; j < i; j++) 
        {
            hinfo l = v[j];
            if (l.at > r.at && l.score > r.score) 
            {
                flag = false; 
                break;
            }
        }
        if (!flag)
        {
            continue;
        }

        int hhap = r.at + r.score;
        int hidx = r.idx;
        // 앞사람과 비교해서 인센을 받을수있는 사람만 push 
        // 이때는 합과 idx 만을 가지고 연산하므로 그렇게만넣어주기 
        vp.push_back(make_pair(hhap,hidx));
    }

    // 합의 큰 순서내로 내림차순 
    sort(vp.begin(), vp.end(), comp2);
    
    int answer = 0; 
    int rank = 1;

    for (int i = 0; i < vp.size(); i++) 
    {
        int hsum = vp[i].first; 
        int cnt = 0;
        
        // vp 사이즈 보다 i값이 작고 인사고과의 합이 다음 idx 와 같은 경우
        // 같은 rank 로 확인되며 다음 점수는 그 만큼 rank가 떨어지는것을 구현한 코드 
        while (i < vp.size() && hsum == vp[i].first) 
        {
            if (vp[i].second == 0) 
            {
                answer = rank++; 
                break;
            }
            i++; 
            cnt++;
        }
        // 위에서 한개 더 더해진i 줄이기 
        i--;

        // 그 다음 합계가 같은사람 rank 결과 
        rank += cnt;
        
        if (answer != 0)
        {
            break;
        }
    }
    
    if (answer == 0)
    {
        return -1;
    }
    else
    {
        return answer;
    }
}

int main()
{
    vector<vector<int>> vv = { {2,2},{1,4},{3,2},{3,2},{2,1} };
    int dab = solution(vv);
    if (dab == 4)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << "error" << endl;
    }
}


/*
각 사원마다 근무 태도 점수와 동료 평가 점수가 기록되어 있는데 
만약 어떤 사원이 다른 임의의 사원보다 두 점수가 모두 낮은 경우가 한 번이라도 있다면 그 사원은 인센티브를 받지 못합니다. 
그렇지 않은 사원들에 대해서는 두 점수의 합이 높은 순으로 석차를 내어 석차에 따라 인센티브가 차등 지급됩니다. 
이때, 두 점수의 합이 동일한 사원들은 동석차이며, 동석차의 수만큼 다음 석차는 건너 뜁니다. 
예를 들어 점수의 합이 가장 큰 사원이 2명이라면 1등이 2명이고 2등 없이 다음 석차는 3등부터입니다.

각 사원의 근무 태도 점수와 동료 평가 점수 목록 scores이 주어졌을 때, 완호의 석차를 return 하도록 solution 함수를 완성해주세요.

제한 사항
1 ≤ scores의 길이 ≤ 100,000
scores의 각 행은 한 사원의 근무 태도 점수와 동료 평가 점수를 나타내며 {a, b} 형태입니다.
scores{0}은 완호의 점수입니다.
0 ≤ a, b ≤ 100,000
완호가 인센티브를 받지 못하는 경우 -1을 return 합니다.
입출력 예
scores	result
{{2,2},{1,4},{3,2},{3,2},{2,1}}	4
입출력 예 설명
5 번째 사원은 3 번째 또는 4 번째 사원보다 근무 태도 점수와 동료 평가 점수가 모두 낮기 때문에 인센티브를 받을 수 없습니다. 2 번째 사원, 3 번째 사원, 4 번째 사원은 두 점수의 합이 5 점으로 최고점이므로 1 등입니다. 1 등이 세 명이므로 2 등과 3 등은 없고 1 번째 사원인 완호는 두 점수의 합이 4 점으로 4 등입니다.
*/