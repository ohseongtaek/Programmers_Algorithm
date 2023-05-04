#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int xnum = 0; 
    int num = 0;
    for (int i = 0; i < polynomial.size(); i++)
    {
        if (polynomial[i] == 'x')
        {
            if (polynomial[i - 1] == ' ')
            {
                xnum += 1; 
            }
            else if (i == 0) xnum += 1; //0번째 인덱스에 x가 온 경우
            else if ((polynomial[i - 1]) >= '0' && (polynomial[i - 1]) <= '9' && (polynomial[i - 2]) >= '1' && (polynomial[i - 2]) <= '9')
            { //2자리수인 경우
                int temp = ((polynomial[i - 2] - '0') * 10) + (polynomial[i - 1] - '0');
                xnum += temp;
            }
            else xnum += (polynomial[i - 1] - '0'); //문자를 int로 변환 -> 한 자리 수인 경우
        }
        //숫자만 고려
        else if ((polynomial[i]) >= '0' && (polynomial[i]) <= '9' && polynomial[i + 1] != 'x')
        {
            //한 자리 수인 경우
            if ((polynomial[i - 1] == ' ' || i == 0) && ((i == polynomial.size() - 1) || polynomial[i + 1] == ' '))
            {
                num += (polynomial[i] - '0'); 
                printf("%d\n", num);
            }
            //두 자리 수인 경우
            else if ((polynomial[i]) >= '0' && (polynomial[i]) <= '9' && (polynomial[i - 1]) >= '1' && (polynomial[i - 1]) <= '9')
            {
                int temp = ((polynomial[i - 1] - '0') * 10) + (polynomial[i] - '0');
                num += temp;
            }
        }
    }//for문 끝나는 시점

    if (xnum > 0 && num > 0) //x계수, 상수항 모두 존재 경우
    {
        if (xnum > 1)
        {
            //sprintf(answer.c_str(), "%dx + %d", xnum, num); //x계수가 1인 경우
            answer = to_string(xnum) + "x + " + to_string(num);
        }
        else
        {
            answer = "x + " + to_string(num);
            //sprintf(answer, "x + %d", num);
        }
    }
    else if (xnum > 0 && num == 0) //x계수만 존재하는 경우
    {
        if (xnum > 1)
        {
            //sprintf(answer, "%dx", xnum);
            answer = to_string(xnum) + "x";
        }
        else answer = "x";
    }
    else
    {
        //sprintf(answer, "%d", num); //상수항만 존재 경우
        answer = to_string(num);
    }
    return answer;
}

int main() {
    string p1 = "3x + 7 + x";
    cout << solution(p1) << endl;  // "4x + 7"

    string p2 = "x + x + x";
    cout << solution(p2) << endl;  // "3x"

    return 0;
}
