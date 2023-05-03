#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        int a = arr[i];

        for (int j = 0; j < a; j++)
        {
            answer.push_back(a);
        }
    }

    return answer;
}