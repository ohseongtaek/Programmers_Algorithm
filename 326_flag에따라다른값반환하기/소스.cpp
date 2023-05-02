#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) 
{
    int answer = 0;

    if (flag == true)
    {
        answer = a + b;
    }
    else
    {
        answer = a -b;
    }

    return answer;
}

int main()
{
    int a = -4;
    int b = 7;

    int ttt = a - b;
    
    cout << ttt << endl;
}