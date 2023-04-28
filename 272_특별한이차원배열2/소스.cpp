#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) 
{
    int answer = true;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                answer = false;
                break;
            }
        }

        if (answer == false)
        {
            break;
        }
    }


    return answer;
}