#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) 
{
    int answer = 0;

    int y1 = date1[0] * 12 * 30;
    int m1 = date1[1] * 30;
    int d1 = date1[2];

    int y2 = date2[0] * 12 * 30;
    int m2 = date2[1] * 30;
    int d2 = date2[2];

    long long F = y1 + m1 + d1;
    long long S = y2 + m2 + d2;

    if (F < S)
    {
        answer = true;
    }
    else
    {
        answer = false;
    }

    return answer;
}