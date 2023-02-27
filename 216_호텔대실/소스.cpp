#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
    {
        return a.first < b.first;
    }
    else if (a.first == b.first)
    {
        return a.second < b.second;
    }
}

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    vector<pair<int, int>> vp;

    for (int i = 0; i < book_time.size(); i++)
    {
        pair<int, int> p;
        string start = book_time[i][0];
        string end = book_time[i][1];

        int hour = stoi(start.substr(0, 2));
        int min = stoi(start.substr(3, 2));

        p.first = hour * 100 + min;

        hour = stoi(end.substr(0, 2));
        min = stoi(end.substr(3, 2));

        if (min >= 50)
        {
            hour += 1;
            min -= 50;
        }
        else
        {
            min += 10;
        }

        p.second = hour * 100 + min;

        vp.push_back(p);
    }

    sort(vp.begin(), vp.end());
    vector<pair<int, int>> visit;

    for (auto a : vp)
    {
        int start = a.first;
        vector<pair<int, int>> tmp;

        for (auto r : visit)
        {
            if (start < r.second)
            {
                tmp.push_back(r);
            }
        }

        visit = tmp;
        visit.push_back(a);
        answer = max(answer, (int)visit.size());
    }

    return answer;
}

int main()
{
    vector<vector<vector<string>>> v = { {{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}},
                                        {{"09:10", "10:10"}, {"10:20", "12:20"}},
                                        {{"10:20", "12:30"}, {"10:20", "12:30"}, {"10:20", "12:30"}},
                                        {{"16:00", "16:10"}, {"16:20", "16:30"}, {"16:40", "16:50"}}
                                        };
    vector<int> d = { 3,1,3,1 };

    for (int i = 0; i < d.size(); i++)
    {
        int dab = solution(v[i]);

        if (dab == d[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}