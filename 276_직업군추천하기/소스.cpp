#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}


string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    vector<vector<string>> v;
    vector<pair<string, int>> Lang_score;

    for (int i = 0; i < table.size(); i++)
    {
        string str = table[i];
        string s = "";
        stringstream stream(str);
        vector<string> temp_v;
        while (stream >> s)
        {
            temp_v.push_back(s);
        }
        v.push_back(temp_v);
    }

    int max_count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;

        for (int j = 1; j < v[i].size(); j++)
        {
            for (int k = 0; k < languages.size(); k++)
            {
                if (languages[k] == v[i][j])
                {
                    int gop = v[i].size() - j;
                    sum += gop * preference[k];
                }
            }
        }
        if (max_count <= sum)
        {
            max_count = sum;
            Lang_score.push_back(make_pair(v[i][0], sum));
        }
    }
    
    sort(Lang_score.begin(), Lang_score.end(),cmp);

    answer = Lang_score[0].first;
    return answer;
}

int main()
{
    vector<string> t = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" };

    vector<string> l = { "PYTHON", "C++", "SQL" };
    vector<int> p = { 7,5,5 };

    string r = solution(t, l, p);

    cout << r << endl;
}