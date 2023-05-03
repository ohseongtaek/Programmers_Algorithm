#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) 
{
    vector<string> answer;

    string test = "";
    for (int i = 0; i < myStr.size(); i++)
    {
        if (myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c')
        {
            if (test == "")
            {
                continue;
            }
            answer.push_back(test);
            test = "";
        }
        else
        {
            test += myStr[i];
        }
    }

    if (test != "")
    {
        answer.push_back(test);
    }

    if (answer.size() == 0)
    {
        answer.push_back("EMPTY");
    }

    return answer;
}