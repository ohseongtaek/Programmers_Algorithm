#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) 
{
    int answer = 0;
    int size = common.size();
    if (common[1] - common[0] == common[2] - common[1])
    {
        answer = common[size - 1] + common[1] - common[0];
    }
    else
    {
        int gob = common[1] / common[0];
        answer = common[size - 1] * gob;
    }


    return answer;
}
