#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) 
{
    vector<string> answer;
    
    int idx = 0;
    for (int i = 0; i < names.size(); i++)
    {
        if (idx == 0)
        {
            answer.push_back(names[i]);
        }
        idx++;

        if (idx == 5)
        {
            idx = 0;
        }
    }

    
    return answer;
}