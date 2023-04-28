#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int brr[100001];
int hap[1000001];

string solution(string a, string b) 
{
    string answer = "";
    memset(arr, 0, sizeof(arr));
    memset(brr, 0, sizeof(brr));
    memset(hap, 0, sizeof(hap));

    int LS = 0;
    int idx = a.size()-1;
    for (int i = 0; i < a.size(); i++)
    {
        arr[i] = a[idx-i] - '0';
    }

    idx = b.size() - 1;
    for (int i = 0; i < b.size(); i++)
    {
        brr[i] = b[idx - i] - '0';
    }

    if (a.size() > b.size())
    {
        LS = a.size();
    }
    else
    {
        LS = b.size();
    }

    for (int i = 0; i < LS; i++)
    {
        hap[i] += arr[i] + brr[i];
        if (hap[i] >= 10)
        {
            hap[i + 1]++;
            hap[i] -= 10;
        }

        answer = answer + to_string(hap[i]);
    }

    if (hap[LS] == 1)
    {
        answer = answer + "1";
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    //solution("18446744073709551615", "287346502836570928366");

    solution("582",
        "734");
}