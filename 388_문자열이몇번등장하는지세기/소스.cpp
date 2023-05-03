#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) 
{
    int answer = 0;
    
    for (int i = 0; i < myString.size(); i++)
    {
        string test = "";
        for (int j = i; j < i + pat.size(); j++)
        {
            test += myString[j];
        }

        if (test.find(pat) == string::npos)
        {

        }
        else
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    solution("banana", "ana");
}