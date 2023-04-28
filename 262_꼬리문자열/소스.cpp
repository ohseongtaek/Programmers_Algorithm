#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) 
{
    string answer = "";

    for (int i = 0; i < str_list.size(); i++)
    {
        string temp = str_list[i];
        if (temp.find(ex) == string::npos)
        {
            answer += temp;
        }
        else
        {
            continue;
        }
    }

    return answer;
}