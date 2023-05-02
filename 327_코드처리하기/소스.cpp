#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";

    bool m = false;

    for (int i = 0; i < code.size(); i++)
    {
        if (code[i] == '1')
        {
            m = !m;
            continue;
        }

        if (m == false)
        {
            if (i % 2 == 0)
            {
                answer += code[i];
            }
        }
        else
        {
            if (i % 2 == 1)
            {
                answer += code[i];
            }
        }
    }

    if (answer == "")
    {
        answer = "EMPTY";
    }


    return answer;
}