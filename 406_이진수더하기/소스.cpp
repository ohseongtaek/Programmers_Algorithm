#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) 
{
    string answer = "";

    int n = 1;
    int b1 = bin1.size() - 1;
    int b2 = bin2.size() - 1;

    int sum1 = 0;
    int sum2 = 0;

    while (true)
    {
        int v = bin1[b1] - '0';
        sum1 += v * n;
        n = n * 2;
        b1--;
        
        if (b1 == -1)
        {
            break;
        }
    }

    n = 1;

    while (true)
    {
        int v = bin2[b2] - '0';
        sum2 += v * n;
        n = n * 2;
        b2--;

        if (b2 == -1)
        {
            break;
        }
    }

    int sum = sum1 + sum2;

    while (true)
    {
        string test = to_string(sum % 2);
        sum = sum / 2;
        answer = test + answer;
        if (sum == 0)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    solution("10", "11");
}