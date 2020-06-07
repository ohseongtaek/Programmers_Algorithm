#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;                           // 전체반복횟수 
    for (int i = 0; i < t; i++)
    {
        int r;                          //문자열 반복획수 
        string p;                       // 문자열 정의 
        cin >> r;
        cin >> p;

        for (int j = 0; j < p.length(); j++)        // 문자열의 크기만큼 반복 첫번째 문자열이 a이면 밑에서 출력 이후 b가오고 c가오면서 해당 문자열을 출력해준다  
        {
            for (int k = 0; k < r; k++)             // 문자열 반복횟수 만큼 반복 r만큼이니 4번이면 해당 문자열 4번해서 abc입력시 aaaa를 밑에서 출력하는것 
            {
                cout << p[j];                          // a를 출력한다 
            }
        }
        cout << endl;
    }
    return 0;
}
