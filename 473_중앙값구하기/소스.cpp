#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> array) 
{
    int answer = 0;

    sort(array.begin(), array.end());

    if (array.size() % 2 == 0)
    {
        answer = array[array.size() / 2 + 1];
    }
    else
    {
        answer = array[array.size() / 2];
    }


    return answer;
}