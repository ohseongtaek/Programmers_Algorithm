#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) 
{
    int answer = 0;
    map<int, int> m;
    map<int, int>::iterator iter;

    for (int i = 0; i < array.size(); i++)
    {
        m[array[i]]++;
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        answer = max(answer, iter->second);
    }
    int cnt = 0;
    int hi = 0;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (answer == iter->second)
        {
            hi = iter->first;
            cnt++;
        }
    }

    if (cnt >= 2)
    {
        answer = -1;
    }
    else
    {
        answer = hi;
    }


    return answer;
}

int main()
{
    solution({ 0,0,1,1,1,2 });
}