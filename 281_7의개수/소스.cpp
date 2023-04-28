#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) 
{
    int answer = 0;

    for (int i = 0; i < array.size(); i++)
    {
        string test = to_string(array[i]);
        for (int j = 0; j < test.size(); j++)
        {
            if (test[j] == '7')
            {
                answer++;
            }
        }
    }

    return answer;
}