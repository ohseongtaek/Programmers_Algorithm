#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) 
{
    string answer = "";
    
    for (int i = 0; i < my_string.size(); i++)
    {
        const char *t = alp.c_str();
        char t2 = my_string[i];

        if (*t == t2)
        {
            answer += toupper(my_string[i]);
        }
        else
        {
            answer += my_string[i];
        }
    }

    return answer;
}

int main()
{
    solution("programmers", "p");
}