#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> answer;

    string test = "";

    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] == ' ')
        {
            answer.push_back(test);
            test = "";
        }
        else
        {
            test += my_string[i];
        }
    }

    answer.push_back(test);

    return answer;
}