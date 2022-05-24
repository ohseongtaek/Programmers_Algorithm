#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> Number_list = {"zero","one","two","three","four","five","six","seven","eight","nine" };

string Changed(string s)
{
    string strRet = "";
    if (s == "one")
    {
        strRet = "1";
    }
    else if (s == "two")
    {
        strRet = "2";
    }
    else if (s == "three")
    {
        strRet = "3";
    }
    else if (s == "four")
    {
        strRet = "4";
    }
    else if (s == "five")
    {
        strRet = "5";
    }
    else if (s == "six")
    {
        strRet = "6";
    }
    else if (s == "seven")
    {
        strRet = "7";
    }
    else if (s == "eight")
    {
        strRet = "8";
    }
    else if (s == "nine")
    {
        strRet = "9";
    }
    else if (s == "zero")
    {
        strRet = "0";
    }

    return strRet;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < Number_list.size(); i++)
    {
		if (string::npos != s.find(Number_list[i]))
		{
            // 찾은 문자열을 숫자로 치환 
            s.replace(s.find(Number_list[i]), Number_list[i].size(), Changed(Number_list[i]));

            // 같은 문자열이 또 있는지확인
			while (string::npos != s.find(Number_list[i]))
			{
                s.replace(s.find(Number_list[i]), Number_list[i].size(), Changed(Number_list[i]));
			}
		}
    }
    answer = stoi(s);
    return answer;
}

int main()
{
    vector<string> input = { "oneone4seveneight", "23four5six7", "2three45sixseven", "123"};
    for (int i = 0; i < input.size(); i++)
    {
        int output = solution(input[i]);
        cout << output << endl;
    }

    return 0;
}