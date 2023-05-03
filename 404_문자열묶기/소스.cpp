#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int solution(vector<string> strArr) 
{
    int answer = 0;

    map<int, int> m;
    map<int, int>::iterator iter;

    for (int i = 0; i < strArr.size(); i++)
    {
        m[strArr[i].size()]++;
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        answer = max(answer, iter->second);
    }

    return answer;
}