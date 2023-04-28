#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) 
{
    vector<vector<int>> answer;

    int row = arr.size();
    int col = arr[0].size();

    if (row == col)
    {
        answer = arr;
    }
    else
    {
        if (row > col)
        {
            int diff = row - col;
            for (int i = 0; i < arr.size(); i++)
            {
                vector<int>& tmp = arr[i];
                for (int j = 0; j < diff; j++)
                {
                    tmp.push_back(0);
                }
            }
            answer = arr;
        }
        else
        {
            int diff = col - row;
            vector<int> tmp;
            for (int i = 0; i < arr[0].size(); i++)
            {
                tmp.push_back(0);
            }
            for (int j = 0; j < diff; j++)
            {
                arr.push_back(tmp);
            }
            answer = arr;
        }
    }


    return answer;
}