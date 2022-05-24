#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 이분탐색 
// 시간을 주고 중간 값으로 가능한지 지속적으로 확인 

typedef long long ll;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) 
{
    ll llstart = 0;

    // 최악의 시간 = 10의9승만큼 금 은이 필요하고, 옮길수있는게 1개이며 그 1개움직이는 시간이 10의 5승인 경우 (마지막 10e5 는 편도) 
    ll llend = (10e5 * 2) * ((2 * 10e9) / 1) + 10e5;
    ll answer = llend;

    int icitysize = g.size();

    while (llstart <= llend)
    {
        // 중간값 계산 
        ll llmidValue = (llstart + llend) / 2;

        ll lltotalgold = 0;
        ll lltotalsil = 0;
        ll lltotalGS = 0;

        for (int i = 0; i < icitysize; i++)
        {
            ll llgetMaxweight = 0;
            ll llroundtrip_cnt = 0;
            
            // 왕복 시간 계산
            if (llmidValue % ((ll)t[i] * 2) >= t[i])
            {
                llgetMaxweight = (llmidValue / ((ll)t[i] * 2) + 1) * w[i];
            }
            else
            {
                llgetMaxweight = (llmidValue / ((ll)t[i] * 2)) * w[i];
            }


            // 금 계산
            if ((ll)g[i] <= llgetMaxweight)
            {
                lltotalgold += (ll)g[i];
            }
            else
            {
                lltotalgold += llgetMaxweight;
            }

            // 은 계산
            if ((ll)s[i] <= llgetMaxweight)
            {
                lltotalsil += (ll)s[i];
            }
            else
            {
                lltotalsil += llgetMaxweight;
            }

            // 금+은 계산 
            if (((ll)g[i]+ (ll)s[i]) <= llgetMaxweight)
            {
                lltotalGS += (ll)g[i] + (ll)s[i];
            }
            else
            {
                lltotalGS += llgetMaxweight;
            }

        }

        // 운반 가능한 시간이면 최솟값 넣기 
        if ((lltotalgold >= a) && (lltotalsil >= b) && (lltotalGS >= (a + b)))
        {
            llend = llmidValue - 1;
            answer = min(llmidValue, answer);
        }
        else
        {
            llstart = llmidValue + 1;
        }
    }
    return answer;
}


int main()
{
    vector<int> a = { 10,90 };
    vector<int> b = { 10,500 };

    vector<vector<int>> g = { {100},{70,70,0} };
    vector<vector<int>> s = { {100},{0,0,500} };
    vector<vector<int>> w = { {7},{100,100,2} };
    vector<vector<int>> t = { {10},{4,8,1} };

    vector<int> r = { 50,499 };

    for (int i = 0; i < g.size(); i++)
    {
        long long time = solution(a[i], b[i], g[i], s[i], w[i], t[i]);
        
        if (r[i] == time)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << time << ", [want]" << r[i] << endl;
        }
        cout << endl;
    }

    return 0;
}


/*
int a => 짓는데 필요한 금 kg 
int b => 짓는데 필요한 은 kg
vector<int> g => g[i] 도시의 금량 
vector<int> s => s[i] 도시의 은량 
vector<int> w => w[i] 최대 운반 가능 무게 
vector<int> t => t[i] 편도 시간 

제한사항
0 ≤ a, b ≤ 109
1 ≤ g의 길이 = s의 길이 = w의 길이 = t의 길이 = 도시 개수 ≤ 105
0 ≤ g[i], s[i] ≤ 109
1 ≤ w[i] ≤ 102
1 ≤ t[i] ≤ 105

이해 => 한개의 도시를 짓는데 여러 도시들이 도움을 주는것임 (1:N 관계)
    => 하지만 도시를 짓는곳에 도움을 주는 도시들이 운행할수있는 트럭은 모두 1개임
    => 각 도시들이 가지고 있는 광물들도 제한적임 
    => 따라서 아래 제한사항이 생김 
        a ≤ g의 모든 수의 합
        b ≤ s의 모든 수의 합

최종 => 금 과 은 중 가장 늦게 운반되는것을 기준으로 왕복+1번편도를 리턴하면 될듯..?


*/
