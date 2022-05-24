#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int wordCnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            wordCnt = 0;
            answer += s[i];
            continue;
        }
        else
        {
            // 짝수 : 소문자->대문자, 대문자는 그대로
            if (wordCnt % 2 == 0)
            {
                if ('A' <= s[i] && s[i] <= 'Z')
                {
                    answer = answer + s[i];
                }
                else
                {
                    answer = answer + char(s[i] - 'a' + 'A');
                }
            }
            // 홀수 : 대문자 소문자 소문자는 그대로 
            else
            {
                if ('a' <= s[i] && s[i] <= 'z')
                {
                    answer = answer + s[i];
                }
                else
                {
                    answer = answer + char(s[i] - 'A' + 'a');
                }
            }
        }
        wordCnt++;
    }

    return answer;
}