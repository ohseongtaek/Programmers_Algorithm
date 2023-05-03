#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) 
{
    vector<int> answer;

    int idx = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        idx++;
        if (idx >= n)
        {
            answer.push_back(num_list[i]);
        }
    }

    return answer;
}