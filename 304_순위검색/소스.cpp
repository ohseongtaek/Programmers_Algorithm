
/* 시간 초과 코드 
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> info_A;
    vector<vector<string>> query_A;

    for (int i = 0; i < query.size(); i++) {
        string A = query[i];
        istringstream ss(A);
        string buffer;
        vector<string> temp;
        while (getline(ss, buffer, ' ')) {
            if (buffer != "-" && buffer != "and") {
                temp.push_back(buffer);
            }
            else if (buffer == "-") {
                string k = "empty";
                temp.push_back(k);
            }
        }
        query_A.push_back(temp);
    }
    
    for (int i = 0; i < info.size(); i++) {
        string A = info[i];
        istringstream ss(A);
        string buffer;
        vector<string> temp;
        while (getline(ss, buffer, ' ')) {
            if (buffer != "-" && buffer != "and") {
                temp.push_back(buffer);
            }
        }
        info_A.push_back(temp);
    }

    for (int i = 0; i < query_A.size(); i++) {
        vector<string> diff;
        int count = 0;
        for (int j = 0; j < query_A[i].size(); j++) {
            diff.push_back(query_A[i][j]);
        }

        for (int j = 0; j < info_A.size(); j++) {

            bool broken = false;
            for (int k = 0; k < info_A[j].size(); k++) {
                if (diff[k] == "empty" || diff[k] == info_A[j][k]) {
                    continue;
                }
                else {
                    //cout << "CHECK = " << diff[k] << " " << info_A[j][k] << endl;
                    if (k == diff.size() - 1) {
                        if (stoi(diff[k]) <= stoi(info_A[j][k])) {
                            continue;
                        }
                        else {
                            broken = true;
                            break;
                        }
                    }
                    else {
                        broken = true;
                        break;
                    }
                }
            }
            if (!broken) {
                //cout << "i j " << i << " " << j << endl;
                count++;
            }
        }
        answer.push_back(count);
        diff.clear();
    }
    return answer;

}
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<int>> mp;

void PushAll(string *s, int score)
{
    // 총 4개 
    for (int i = 0; i < 16; i++)
    {
        string str = "";
        int a = i;
        for (int j = 3; j >= 0; j--)
        {
            if (a <= 0 || a % 2 == 0)
            {
                str = "-" + str;
            }
            else
            {
                str = s[j] + str;
            }
            a = a / 2;
        }
        mp[str].push_back(score);
        //cout << i << " " <<  str << "   " << score << endl;
    }

}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    string s[4];
    string str = "";

    // 기준
    for (int i = 0; i < info.size(); i++)
    {
        istringstream ss(info[i]);

        // 언어 , 종류 , 직책 , 음식 , 점수 
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> str;

        // 종류 얻어오기 
        PushAll(s, stoi(str));
    }

    // 점수정렬 
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        sort(iter->second.begin(), iter->second.end());
    }

    /* Debug Code 
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << " ";
        for (int i = 0; i < iter->second.size(); i++)
        {
            cout << iter->second[i] << " ";
        }
        cout << endl;
    }
    */

    // 지원자 
    for (int i = 0; i < query.size(); i++)
    {
        int score;
        istringstream ss(query[i]);
        // 언어 , 종류 , 직책 , 음식 , 점수 
        ss >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str;
        score = stoi(str);

        vector<int> v = mp[s[0] + s[1] + s[2] + s[3]];
        if (v.size() != 0)
        {
            auto iter2 = lower_bound(v.begin(), v.end(),score);
            answer.push_back(v.size() - (iter2 - v.begin()));
        }
        else
        {
            answer.push_back(0);
        }
    }

    return answer;
}

int main() {
    vector<string> a = { "java backend junior pizza 150",
                        "python frontend senior chicken 210",
                        "python frontend senior chicken 150",
                        "cpp backend senior pizza 260",
                        "java backend junior chicken 80",
                        "python backend senior chicken 50" };

    vector<string> b = { "java and backend and junior and pizza 100",
                        "python and frontend and senior and chicken 200",
                        "cpp and - and senior and pizza 250",
                        "- and backend and senior and - 150",
                        "- and - and - and chicken 100",
                        "- and - and - and - 150" };

    vector<int> answer = solution(a, b);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    cout << endl;
}