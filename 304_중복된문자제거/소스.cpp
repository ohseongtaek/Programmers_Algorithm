#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string my_string) 
{
    string answer = "";
    map<char, int> m;
    map<char, int>::iterator iter;
    
    for (int i = 0; i < my_string.size(); i++)
    {
        iter = m.find(my_string[i]);

        if (iter == m.end())
        {
            answer += my_string[i];
            m.insert(make_pair(my_string[i], i));
        }

    }

    return answer;
}