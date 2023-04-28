#include <string>
#include <vector>

using namespace std;

string solution(string myString) 
{
    string answer = "";

    for (int i = 0; i < myString.size(); i++)
    {
        char temp = myString[i];

        if (temp - 'a' < 11)
        {
            myString[i] = 'l';
        }

    }

    answer = myString;

    return answer;
}