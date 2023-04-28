#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) 
{
    int answer = 0;
    vector<pair<int, int>> vp;
    for (int i = 0; i < array.size(); i++)
    {
        int cal = abs(n - array[i]);
        vp.push_back(make_pair(cal, array[i]));
    }

    sort(vp.begin(), vp.end());
    answer = vp[0].second;
    
    return answer;
}