#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) 
{
    int answer = 0;

    vector<string> v;
    string test = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        test += my_string[i];
        v.push_back(test);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == is_prefix)
        {
            answer = true;
            break;
        }
    }

    return answer;
}