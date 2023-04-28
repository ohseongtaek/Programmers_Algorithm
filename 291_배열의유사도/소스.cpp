#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) 
{
    int answer = 0;

    for (int i = 0; i < s1.size(); i++)
    {
        string tmp = s1[i];

        for (int j = 0; j < s2.size(); j++)
        {
            if(s2[j] == tmp)
            { 
                answer++;
            }
        }
    }

    return answer;
}