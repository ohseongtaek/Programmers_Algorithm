#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    cin >> str; //55-50+40
    int result = 0;
    string temp = "";
   
    bool minus = false;
    for (int i = 0; i <= str.size(); i++)
    {
        //연산자일 경우
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if (minus)
                result = result - stoi(temp);
            else
                result = result + stoi(temp);
            temp = ""; //초기화
            //괄호를 뺄셈 이후에 치면 최소
            if (str[i] == '-'){
                minus = true;
            }
            continue;
        }
        //피연산자일 경우
        temp = temp + str[i];
    }
    cout << result << endl;
    return 0;
}