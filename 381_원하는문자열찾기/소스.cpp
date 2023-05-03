#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) 
{
    int answer = 0;

    string temp = "";
    string temp2 = "";
    for (int i = 0; i < myString.size(); i++)
    {
        temp += toupper(myString[i]);
    }

    for (int i = 0; i < pat.size(); i++)
    {
        temp2 += toupper(pat[i]);
    }

    int idx = temp.find(temp2);

    if (idx == string::npos)
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
    solution("AbCdEfG","aBc");
}
