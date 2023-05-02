#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) 
{
    vector<int> answer;

    answer = num_list;

    int last = num_list[num_list.size() - 1];
    int lastm1 = num_list[num_list.size() - 2];

    if (last > lastm1)
    {
        answer.push_back(last - lastm1);
    }
    else
    {
        answer.push_back(last * 2);
    }

    
    return answer;
}