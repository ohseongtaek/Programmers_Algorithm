#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += price * (i + 1);
    }
    answer = sum - money > 0 ? sum - money : 0;
    return answer ;
}

int main()
{
    int p = 3;
    int m = 20;
    int c = 4;
    int r = solution(p, m, c);

    cout << r << endl;
}