#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    string answer = "";

    // √  ∫Ø»Ø
    int temp = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int totalLen = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int opStart = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int opEnd = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));

    if (opStart <= temp && opEnd >= temp)
    {
        temp = opEnd;
    }

    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "prev")
        {
            if (temp - 10 > 0)
            {
                temp -= 10;
            }
            else
            {
                temp = 0;
            }
        }
        else if (commands[i] == "next")
        {
            if (temp + 10 < totalLen)
            {
                temp += 10;
            }
            else
            {
                temp = totalLen;
            }
        }

        if (opStart <= temp && opEnd >= temp)
        {
            temp = opEnd;
        }
    }

    answer = (temp / 60 < 10 ? "0" + to_string(temp / 60) : to_string(temp / 60)) + ":" + (temp % 60 < 10 ? "0" + to_string(temp % 60) : to_string(temp % 60));

    return answer;
}