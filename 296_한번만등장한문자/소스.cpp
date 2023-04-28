#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s) 
{
    string answer = "";
    map<char, int> m;
    map<char, int>::iterator iter;

    for (int i = 0; i < s.size(); i++)
    {
        bool flag = false;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->first == s[i])
            {
                flag = true;
                iter->second++;
            }
        }

        if (flag == false)
        {
            m.insert(make_pair(s[i], 1));
        }
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second == 1)
        {
            answer.push_back(iter->first);
        }
    }

    return answer;
}