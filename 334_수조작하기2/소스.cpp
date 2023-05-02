#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int temp = numLog[0];

    for (int i = 1; i < numLog.size(); i++)
    {
        int k = numLog[i] - temp;
        if (k == -1)
        {
            answer += "s";
        }
        else if (k == 1)
        {
            answer += "w";
        }
        else if (k == -10)
        {
            answer += "a";
        }
        else if (k == 10)
        {
            answer += "d";
        }

        temp = numLog[i];
    }


    return answer;
}