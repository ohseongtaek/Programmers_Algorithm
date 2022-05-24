#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

bool Check(string s)
{
    stack<char> st;
    bool bfirst = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            bfirst = true;
            st.push(s[i]);
        }
        else
        {
            if (bfirst == true)
            {
                if (s[i] == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (s[i] == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() == '[')
                {
                    st.pop();
                }
            }
            else
            {
                break;
            }
        }
    }

    if((st.empty() == true) && bfirst)
    { 
        return true;
    }
    else
    {
        return false;
    }
}

string rotate(string str)
{
    char temp = str[0];
    str.erase(str.begin());
    str += temp;

    return str;
}

int solution(string s) {
    
    int  answer          = 0;
    string str = s;
    
    for (int i = 0; i < s.size(); i++)
    {
        bool bRtn = Check(str);
        if (bRtn == true)
        {
            answer++;
        }
        str = rotate(str);
    }

    return answer;
}

int main()
{
    //"}]()[{"
    //"[)(]"
    //"}}}"	
    string str = "[](){}";
    int nRtn = solution(str);
    cout << nRtn << endl;
    
    return 0;
}