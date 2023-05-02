#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(string my_string) 
{
    vector<int> answer;
    map<char, int> m;
    
    for (char i = 'A'; i <= 'Z'; i++)
    {
        m.insert(make_pair(i, 0));
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        m.insert(make_pair(i, 0));
    }
    for (int i = 0; i < my_string.size(); i++)
    {
        m[my_string[i]]++;
    }

    for (char i = 'A'; i <= 'Z'; i++)
    {
        answer.push_back(m[i]);
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        answer.push_back(m[i]);
    }
    return answer;
}