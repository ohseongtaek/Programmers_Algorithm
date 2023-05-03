#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) 
{
    int answer = 0;

    string temp = "";

    for (int i = 0; i < myString.size(); i++)
    {
        if (myString[i] == 'A')
        {
            myString[i] = 'B';
        }
        else if (myString[i] == 'B')
        {
            myString[i] = 'A';
        }
    }

    if (myString.find(pat) == string::npos)
    {
        answer = 0;
    }
    else
    {
        answer = 1;
    }

    return answer;
}