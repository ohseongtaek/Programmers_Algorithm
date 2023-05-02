#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) 
{
    string answer = "";
    vector<string> v;
    
    int idx = 0;
    string test = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        test += my_string[i];
        idx++;
        if (idx == m)
        {
            v.push_back(test);
            test = "";
            idx = 0;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        answer += v[i][c-1];
    }

    return answer;
}

int main()
{
    solution("ihrhbakrfpndopljhygc", 4, 2);
}