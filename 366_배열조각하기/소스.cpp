#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) 
{
    vector<int> answer;
    vector<int> v = arr;
    for (int i = 0; i < query.size(); i++)
    {
        int t = query[i];
        vector<int> vt;
        if (i == 0 || i % 2 == 0)
        {
            for (int j = 0; j <= t; j++)
            {
                vt.push_back(v[j]);
            }
            v.clear();
            v = vt;
        }
        else
        {
            for (int j = t; j < v.size(); j++)
            {
                vt.push_back(v[j]);
            }
            v.clear();
            v = vt;
        }
    }

    answer = v;
    return answer;
}

int main()
{
    solution({ 0, 1, 2, 3, 4, 5 }, { 4, 1, 2 });
}