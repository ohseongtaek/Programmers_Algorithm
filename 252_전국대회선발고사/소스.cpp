#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<int> rank, vector<bool> attendance) 
{
    int answer = 0;
    vector<pair<int, int>> vp;
    for (int i = 0; i < rank.size(); i++)
    {
        if (attendance[i] == true)
        {
            vp.push_back(make_pair(i, rank[i]));
        }
    }

    sort(vp.begin(), vp.end(), comp);

    answer = vp[0].first * 10000;
    answer += vp[1].first * 100;
    answer += vp[2].first;

    return answer;
}

int main()
{
    vector<vector<int>> r = { {3, 7, 2, 5, 4, 6, 1} ,{1, 2, 3} ,{6, 1, 5, 2, 3, 4} };
    vector<vector<bool>> b = { {false, true, true, true, true, false, false} ,{true, true, true}, {true, false, true, false, false, true} };
    vector<int> d = { 20403,102,50200 };
 
    for (int i = 0; i < d.size(); i++)
    {
        int dd = solution(r[i], b[i]);
    }
}