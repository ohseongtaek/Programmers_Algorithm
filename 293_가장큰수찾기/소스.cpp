#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) 
{
    vector<int> answer(2,0);
    int tmpmax = 0;

    for (int i = 0; i < array.size(); i++)
    {
        if (tmpmax <= array[i])
        {
            answer[0] = array[i];
            answer[1] = i;
            tmpmax = array[i];
        }
    }

    return answer;
}