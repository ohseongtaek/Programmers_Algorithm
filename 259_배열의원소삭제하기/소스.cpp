#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) 
{
    vector<int> answer;
    vector<int> vidx;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        bool flag = false;
        for (int j = 0; j < delete_list.size(); j++)
        {
            if (temp == delete_list[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            answer.push_back(temp);
        }
    }

    return answer;
}