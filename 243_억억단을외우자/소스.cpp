#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//힌트 약수 정보와 함께 DP 로 풀어야함 
struct numInfo
{
    int num;
    int numCnt;
};

numInfo DP[5000001];

bool comp(numInfo& a, numInfo& b) 
{
    if (a.numCnt == b.numCnt)
    {
        return a.num < b.num;
    }
    else
    {
        return a.numCnt > b.numCnt;
    }
    
}

vector<int> solution(int e, vector<int> starts) 
{
    vector<int> answer;
    
    for (int i = 1; i <= e; i++) 
    {
        DP[i].num = i;
        for (int k = 1; k <= e / i; k++) 
        {
            DP[i * k].numCnt++;
        }
    }

    sort(DP + 1, DP + e + 1, comp);

    for (auto s : starts) 
    {
        for (int i = 1; i <= e; i++) 
        {
            if (DP[i].num >= s && DP[i].num <= e)
            {
                answer.push_back(DP[i].num);
                break;
            }
        }
    }
    return answer;
}

int main()
{
    int e = 8;
    vector<int> s = { 1,3,7 };
    vector<int> d = { 6,6,8 };

    vector<int> ans = solution(e, s);

    bool flag = true;

    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] != ans[i])
        {
            flag = false;
        }

        if (flag == false)
        {
            break;
        }
    }


    if (flag == false)
    {
        cout << " error " << endl;
    }
    else
    {
        cout << " good " << endl;
    }
}


/*
그림1.png
적당한 수 e를 먼저 정하여 알려주고 e 이하의 임의의 수 s를 여러 개 얘기합니다. 
영우는 각 s에 대해서 s보다 크거나 같고 e 보다 작거나 같은 수 중에서 억억단에서 가장 많이 등장한 수를 답해야 합니다. 
만약 가장 많이 등장한 수가 여러 개라면 그 중 가장 작은 수를 답해야 합니다.

수연은 영우가 정답을 말하는지 확인하기 위해 당신에게 프로그램 제작을 의뢰하였습니다. 
e와 s의 목록 starts가 매개변수로 주어질 때 각 퀴즈의 답 목록을 return 하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ e ≤ 5,000,000
1 ≤ starts의 길이 ≤ min {e,100,000}
1 ≤ starts의 원소 ≤ e
starts에는 중복되는 원소가 존재하지 않습니다.
입출력 예
e	starts	result
8	[1,3,7]	[6,6,8]
입출력 예 설명
억억단에서 1 ~ 8이 등장하는 횟수는 다음과 같습니다.

1번 등장 : 1
2번 등장 : 2, 3, 5, 7
3번 등장 : 4
4번 등장 : 6, 8

[1, 8] 범위에서는 6과 8이 각각 4번씩 등장하여 가장 많은데 6이 더 작은 수이므로 6이 정답입니다.
[3, 8] 범위에서도 위와 같으므로 6이 정답입니다.
[7, 8] 범위에서는 7은 2번, 8은 4번 등장하므로 8이 정답입니다.

*/