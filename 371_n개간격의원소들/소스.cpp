#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) 
{
    vector<int> answer;

    int idx = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        if (i == 0 || idx == n)
        {
            answer.push_back(num_list[i]);
            idx = 0;
        }
        idx++;
    }

    return answer;
}