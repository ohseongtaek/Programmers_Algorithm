#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) 
{
    string answer = "";

    for (int i = 0; i < cipher.size(); i++)
    {
        if (i == 0)
        {
            continue;
        }

        int tt = i + 1;

        if (tt % code == 0)
        {
            answer += cipher[i];
        }
    }

    if (code == 1)
    {
        answer = cipher[0] + answer;
    }

    return answer;
}

int main()
{
    solution("abc", 1);
}