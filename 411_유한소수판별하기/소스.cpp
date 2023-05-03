#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int mod = a % b;

    while (mod > 0)
    {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

bool isPrime1(int n) 
{
    for (int i = 2; i < n; i++) 
    {
        if (n % i == 0) 
        {
            return false;
        }
    }
    
    return true;
}

int solution(int a, int b) 
{
    int answer = 0;

    int ng = gcd(a, b);

    int aa = a / ng;
    int bb = b / ng;

    vector<int> v;

    for (int i = 2; i <= bb; i++)
    {
        if (bb % i == 0)
        {
            if (true == isPrime1(i))
            {
                if (i == 2 || i == 5)
                {
                    //nothing
                }
                else
                {
                    v.push_back(i);
                }
            }
        }
    }

    if (v.size() > 0)
    {
        answer = 2;
    }
    else
    {
        answer = 1;
    }
    

    return answer;
}

int main()
{
    solution(7, 20);
}