#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) 
{
    vector<int> answer;

    for (int i = 0; i < intStrs.size(); i++)
    {
        string temp = intStrs[i];

        temp = temp.substr(s, l);

        int tt = stoi(temp);

        if (tt > k)
        {
            answer.push_back(tt);
        }
    }

    return answer;
}