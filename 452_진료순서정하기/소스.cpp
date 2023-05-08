#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) 
{
    vector<int> answer(emergency.size(),0);
    vector<pair<int, int>> vp;
    for (int i = 0; i < emergency.size(); i++)
    {
        vp.push_back(make_pair(emergency[i], i + 1));
    }

    sort(vp.begin(), vp.end());

    int temp = emergency.size();
    
    for (int i = 0; i < vp.size(); i++)
    {
        answer[vp[i].second - 1] = temp;
        temp--;
    }

    return answer;
}

int main()
{
    solution({ 3,76,24 });
}