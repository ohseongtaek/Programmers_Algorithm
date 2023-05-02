#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) 
{
    int answer = 0;

    vector<string> v;

    string test = "";
    for (int i = my_string.size() - 1; i >= 0; i--)
    {
        test = my_string[i] + test;
        v.push_back(test);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == is_suffix)
        {
            answer = true;
            break;
        }
    }

    return answer;
}