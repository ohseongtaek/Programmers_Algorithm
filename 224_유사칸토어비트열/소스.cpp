#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) 
{
    int answer = 0;

    // 뭐가됐던 5의 배수인걸 생각해야함 11011 과 00000 이기 때문에 
    for (long long i = l; i <= r; i++) 
    {
        int flag = 1;

        // 나머지 3인경우에 11011 에서 0 부분이라 무조건 갯수안셈 
        if (i % 5 == 3) 
        {
            continue;
        }

        long long temp = i;
        long long result;
        
        while (1) 
        {
            if (temp % 5 == 0) 
            {
                temp = temp / 5;
            }
            else 
            {
                temp = (temp / 5) + 1;
            }

            if (temp % 5 == 3) 
            {
                flag = 0;
                break;
            }      
            else if (temp <= 5) 
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1) answer++;
    }

    return answer;
}

int main()
{
    int n = 2;
    int l = 53;
    int r = 53;
    int re = 8;

    if (re == solution(n, l, r))
    {
        cout << " good " <<endl;
    }
    else
    {
        cout << " error"<< endl;
    }
}