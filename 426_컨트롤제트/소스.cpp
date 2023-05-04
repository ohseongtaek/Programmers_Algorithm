#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    vector<string> v;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            v.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }

    if (temp != "")
    {
        v.push_back(temp);
    }

    int n = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "Z")
        {
            answer -= n;
        }
        else
        {
            n = stoi(v[i]);
            answer += n;
        }
    }


    return answer;
}

int main()
{
    solution("1 2 Z 3");
}
