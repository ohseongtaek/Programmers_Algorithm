#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) 
{
    vector<int> answer;
    for (int i = l; i <= r; i++)
    {
        string t = to_string(i);
        bool flag = false;
        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] == '5' || t[j] == '0')
            {

            }
            else
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            answer.push_back(stoi(t));
        }
    }

    if (answer.empty() == true)
    {
        answer.push_back(-1);
    }

    return answer;
}