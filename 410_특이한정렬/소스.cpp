#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }

    return a.first < b.first;
}

vector<int> solution(vector<int> numlist, int n) 
{
    vector<int> answer;

    vector<pair<int, int>> vp;

    for (int i = 0; i < numlist.size(); i++)
    {
        vp.push_back(make_pair(abs(n - numlist[i]), numlist[i]));
    }

    sort(vp.begin(), vp.end(), comp);


    for (int i = 0; i < vp.size(); i++)
    {
        answer.push_back(vp[i].second);
    }

    return answer;
}

int main()
{
    solution({ 1, 2, 3, 4, 5, 6 }, 4);
}