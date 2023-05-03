#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) 
{
    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < num_list.size(); j++)
        {
            if (j == 0)
            {
                temp = num_list[j];
                num_list[j] = num_list[j + 1];
            }
            else if( j == num_list.size() - 1)
            {
                num_list[j] = temp;
            }
            else
            {
                num_list[j] = num_list[j + 1];
            }
        }
    }

    answer = num_list;
    return answer;
}