#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) 
{
    vector<int> answer;

    map<int, int> m;
    map<int, int>::iterator iter;

    for (int i = 0; i < arr.size(); i++)
    {
        if (answer.empty() == true)
        {
            answer.push_back(arr[i]);
        }
        else
        {
            bool flag = false;
            for (int j = 0; j < answer.size(); j++)
            {
                if (answer[j] == arr[i])
                {
                    flag = true;
                    break;
                }
            }

            if (flag == true)
            {

            }
            else
            {
                answer.push_back(arr[i]);
            }
        }

        if (k == answer.size())
        {
            break;
        }
    }

    if (answer.size() < k)
    {
        int x = k - answer.size();

        for (int i = 0; i < x; i++)
        {
            answer.push_back(-1);
        }
    }

    return answer;
}

int main()
{
    solution({ 0, 1, 1, 2, 2, 3 }, 3);
}