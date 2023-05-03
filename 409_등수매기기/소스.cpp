#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) 
{
    vector<int> answer;

    vector<float> v;
    
    for (int i = 0; i < score.size(); i++)
    {
        int k1 = score[i][0] + score[i][1];
        float k = (float)k1 / 2;
        v.push_back(k);
    }

    for (int i = 0; i < v.size(); i++)
    {
        int idx = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                if (v[i] < v[j])
                {
                    idx++;
                }
            }
        }
        answer.push_back(idx);
    }

    return answer;
}

int main()
{
    solution({ {{1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1}, {9,1}, {0,0}} });
}