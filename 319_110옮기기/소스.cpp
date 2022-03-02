#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (int i = 0; i < s.size(); i++)
    {
        const string OOZ = "110";
        string str = s[i];
        string temp_str = "";
        int count = 0;
        bool b_exist_zero = false;
        int  n_zero_index = -1;
        string add_str_ooz = "";
        

        for (int j = 0; j < s[i].length(); j++)
        {
            temp_str += s[i][j];
            if (temp_str.length() >= 3)
            {
                if (temp_str.substr(temp_str.length() - 3, 3) == "110")
                {
                    count++;
                    temp_str.erase(temp_str.length() - 3, temp_str.length());
                    add_str_ooz += OOZ;
                }
            }
        }

        /* 시간초과 
        while (1)
        {
            int idx = str.find(OOZ);
            if (idx == -1)
            {
                break;
            }
            else
            {
                count++;
                str = str.erase(idx, 3);
                add_str_ooz += OOZ;
            }
        }
        */

        for (int j = temp_str.size(); j >= 0; j--)
        {
            if (temp_str[j] == '0')
            {
                n_zero_index = j;
                break;
            }
        }

        if (n_zero_index == -1)
        {
            temp_str = add_str_ooz + temp_str;
        }
        else
        {
            temp_str.insert(n_zero_index+1, add_str_ooz);
        }

        answer.push_back(temp_str);
    }

    return answer;
}

int main()
{
    vector<string> s = { "1110", "100111100", "0111111010" };
    vector<string> dab = solution(s);

    for (int i = 0; i < dab.size(); i++)
    {
        cout << dab[i] << endl;
    }
}