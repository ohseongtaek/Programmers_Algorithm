#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(string before, string after) 
{
    int answer = 0;
    
    map<char, int> m1;
    map<char, int> m2;
    map<char, int>::iterator iter;

    for (int i = 0; i < 26; i++)
    {
        m1.insert(make_pair(0, 0));
        m2.insert(make_pair(0, 0));
    }

    for (int i = 0; i < before.size(); i++)
    {
        m1[before[i] - 'a']++;
    }
    for (int i = 0; i < after.size(); i++)
    {
        m2[after[i] - 'a']++;
    }

    bool flag = true;

    for (int i = 0; i < m1.size(); i++)
    {
        if (m1[i] != m2[i])
        {
            flag = false;
            break;
        }
    }

    if (flag == false)
    {
        answer = 0;
    }
    else
    {
        answer = 1;
    }


    return answer;
}

int main()
{
    solution("olleh", "hello");
}