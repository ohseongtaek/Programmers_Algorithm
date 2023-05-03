#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(string myString) 
{
    vector<string> answer;
    
    string test = "";
    for (int i = 0; i < myString.size(); i++)
    {
        if (myString[i] == 'x')
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
            test += myString[i];
        }
    }

    if (test != "")
    {
        answer.push_back(test);
    }

    sort(answer.begin(), answer.end());

    return answer;
}