#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) 
{
    int answer = 0;

    vector<int> v = arr;
    vector<int> vtemp;
    int idx = 0;
    while (true)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < 50 && v[i] % 2 == 1)
            {
                vtemp.push_back(v[i] * 2 + 1);
            }
            else if (v[i] >= 50 && v[i] % 2 == 0)
            {
                vtemp.push_back(v[i] / 2);
            }
            else
            {
                vtemp.push_back(v[i]);
            }
        }
        
        bool flag = true;
        for (int i = 0; i < vtemp.size(); i++)
        {
            if (vtemp[i] != v[i])
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            answer = idx;
            break;
        }
        else
        {
            idx++;
        }
        v = vtemp;
        vtemp.clear();

    }
    return answer;
}

int main()
{
    solution({ 1, 2, 3, 100, 99, 98 });
}