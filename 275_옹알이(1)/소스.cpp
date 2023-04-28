#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;
    vector<string> go = { "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); i++)
    {
        string tmp = babbling[i];

        for (int j = 0; j < go.size(); j++)
        {
            int idx = 0;
            int gosize = go[j].size();
            
            idx = tmp.find(go[j]);

            if (idx == string::npos)
            {
                continue;
            }
            else
            {
                for (int k = idx; k < idx + gosize; k++)
                {
                    tmp[k] = '_';
                }
            }
        }


        bool flag = false;
        for (int j = 0; j < tmp.size(); j++)
        {
            if (tmp[j] != '_')
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    vector<string> a = { "aya", "yee", "u", "maa", "wyeoo" };
    solution(a);
}