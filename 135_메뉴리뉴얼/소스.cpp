#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


int dwcount[27];
map<string, int> m;
vector<string> menu[27][21];


void nCr(string order, int idx, string made)
{
    if (made.size() > 1)
    {
        m[made]++;
        dwcount[made.size()] = max(dwcount[made.size()], m[made]);
        menu[made.size()][m[made]].push_back(made);
    }
    for (int i = idx + 1; i < order.size(); i++)
    {
        made.push_back(order[i]);
        nCr(order, i, made);
        made.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<pair<int, int>> vp;

    for (string s : orders)
    {
        sort(s.begin(), s.end());
        nCr(s, -1, "");
    }

    for (int i : course)
    {
        if (dwcount[i] > 1)
        {
            for (string s : menu[i][dwcount[i]])
            {
                answer.push_back(s);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> o = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> c = { 2,3,4 };

    vector<string> r = solution(o, c);

    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
}