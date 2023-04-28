#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) 
{
    int answer = 0;

    for (int i = 0; i < order.size(); i++)
    {
        string temp = order[i];
        if (temp.find("latte") == string::npos)
        {
            answer += 4500;
        }
        else
        {
            answer += 5000;
        }
    }

    return answer;
}