#include <string>
#include <vector>

using namespace std;

bool getsosu(int n)
{
    bool brtn;
    int nCnt = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (n % i == 0)
        {
            nCnt++;
        }
    }

    if (nCnt == 2)
    {
        brtn = true;
    }
    else
    {
        brtn = false;
    }

    return brtn;
}

vector<int> solution(int n) 
{
    vector<int> answer;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            bool brtn = getsosu(i);
            if (brtn == true)
            {
                answer.push_back(i);
            }
        }
    }

    return answer;
}