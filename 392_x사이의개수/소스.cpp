#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) 
{
    vector<int> answer;
    string test = "";
    for (int i = 0; i < myString.size(); i++)
    {
        if (myString[i] == 'x')
        {
            answer.push_back(test.size());
            test = "";
        }
        else
        {
            test += myString[i];
        }
    }

    if (test == "")
    {
        answer.push_back(0);
    }
    else
    {
        answer.push_back(test.size());
    }

    return answer;
}