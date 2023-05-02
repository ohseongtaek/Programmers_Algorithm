#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector<pair<int, int>> vp;

    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        pair<int, int> b;
        if (arr[i] == 2)
        {
            b.second = true;
            cnt++;
        }
        b.first = arr[i];
        
        vp.push_back(b);
    }

    bool flag = false;
    for (int i = 0; i < vp.size(); i++)
    {
        
        if (vp[i].second == true)
        {
            flag = true;
            cnt--;
        }

        if (flag == true)
        {
            answer.push_back(vp[i].first);
        }

        if (cnt == 0)
        {
            break;
        }
    }
    
    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }

    return answer;
}

int main()
{
    solution({ 1, 2, 1, 4, 5, 2, 9 });
}