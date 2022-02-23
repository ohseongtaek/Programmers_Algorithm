#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

// n 을 k 진법으로 바꾸는 함수 
string NtoK(int n, int k)
{
    char intToCharList[10] = { '0','1','2','3','4','5','6','7','8','9'};
    string answer = "";

    while (n / k > 0)
    {
        answer = intToCharList[n%k] + answer;
        n = n / k;
    }
    answer = intToCharList[n % k] + answer;

    return answer;
}

bool CheckPrime(string strnum)
{
    long long num = 0;
    try
    {
        num = stoll(strnum);
    }
    catch (const std::exception& e)
    {
        return false;
    }
    
    if (num < 2)
    {
        return false;
    }
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}



// k진법 변환 수 중 소수 찾기 
vector<string> KfindPrime(string k)
{
    vector<string> answer;
    string temp = "";

    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == '0')
        {
            // 소수인지 확인 
            bool bRtn = CheckPrime(temp);
            if (bRtn == true)
            {
                answer.push_back(temp);
            }
            temp = "";
        }
        else if (i == k.size() - 1)
        {
            temp += k[i];
            bool bRtn = CheckPrime(temp);
            if (bRtn == true)
            {
                answer.push_back(temp);
            }
        }
        else
        {
            temp += k[i];
        }
    }
    return answer;
}

// 소수 문자열 P로 변환
string PrimeToP(vector<string> veclist,string k)
{
    string answer = k;
    for (int i = 0; i < veclist.size(); i++)
    {
        answer.replace(answer.find(veclist[i]), veclist[i].size(), "P");
    }
    return answer;
}

int CheckException(string str)
{
    int answer = 0;
    if (str.size() == 1 && str[0] == 'P')
    {
        answer++;
        return answer;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'P')
        {
            if (i == 0)
            {
                if (str[i + 1] == '0')
                {
                    answer++;
                }
            }
            else if (i == str.size() - 1)
            {
                if (str[i - 1] == '0')
                {
                    answer++;
                }
            }
            else
            {
                if ((str[i + 1] == '0') || (str[i - 1] == '0') || (str[i + 1] == '0' && str[i - 1] == '0'))
                {
                    answer++;
                }
            }
        }
    }
    return answer;
}

int solution(int n, int k) {
    int answer = 0;

    // n 을 k 진법으로 바꾸는 함수 
    string to_k = NtoK(n, k);

#ifdef _DEBUG
    cout << "1 = " << to_k << endl;
#endif
    // 10진수 소수 찾기 
    vector<string> find_prime = KfindPrime(to_k);
#ifdef _DEBUG
    for (int i = 0; i < find_prime.size(); i++)
    {
        cout <<"2 = " << find_prime[i] << endl;
    }
#endif

    // 소수 P로 치환 
    string to_P = PrimeToP(find_prime,to_k);
#ifdef _DEBUG
    cout << "3 = " << to_P << endl;
#endif

    // 조건 확인 P0 , 0P, 0P0, P
    answer = CheckException(to_P);

    return answer;
}

int main()
{
    int n = 524287;
    int k = 2;
    int dab = solution(n, k);
    cout << dab << endl;
}