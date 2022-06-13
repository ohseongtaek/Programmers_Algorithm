#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getMaxDivision(int n)
{
    // 루트 !
    int num = sqrt(n);

    // 최대 약수값 get
    for (int i = 2; i <= num; i++) 
    {
        // 10000000 => 이미 깔아놓은 것으로 최대약수가 이것을 넘으면 안됨!
        if (n % i == 0 && n / i <= 10000000)
        {
            return n / i;
        }
    }
    return 1;
}

vector<int> solution(long long begin, long long end) 
{
    vector<int> answer;

    // 각 인덱스에 대해 소수인지 아니면 최대 약수값을 가져오면 된다.
    for (int i = begin; i <= end; i++) 
    {
        answer.push_back(getMaxDivision(i));
    }
    
    
    if (begin == 1)
    {
        answer[0] = 0;
    }

    return answer;
}


int main()
{
    long long b = 1;
    long long e = 10;

    vector<int> answer = { 0, 1, 1, 2, 1, 3, 1, 4, 3, 5 };
    vector<int> dab = solution(b, e);

    bool flag = false;
    for (int i = 0; i < dab.size(); i++)
    {
        if (answer[i] != dab[i])
        {
            cout << " error " << endl;
            flag = true;
            break;
        }
    }

    if (flag == false)
    {
        cout << " good " << endl;
    }
    return 0;
}