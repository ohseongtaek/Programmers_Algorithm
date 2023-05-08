#include <string>
#include <vector>

using namespace std;

string solution(int age) 
{
    string answer = "";

    string temp = to_string(age);

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '0')
        {
            answer += "a";
        }
        else if (temp[i] == '1')
        {
            answer += "b";
        }
        else if (temp[i] == '2')
        {
            answer += "c";
        }
        else if (temp[i] == '3')
        {
            answer += "d";
        }
        else if (temp[i] == '4')
        {
            answer += "e";
        }
        else if (temp[i] == '5')
        {
            answer += "f";
        }
        else if (temp[i] == '6')
        {
            answer += "g";
        }
        else if (temp[i] == '7')
        {
            answer += "h";
        }
        else if (temp[i] == '8')
        {
            answer += "i";
        }
        else if (temp[i] == '9')
        {
            answer += "j";
        }
    }

    return answer;
}