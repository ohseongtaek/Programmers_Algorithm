#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) 
{
    vector<int> answer;

    pair<int, int> cp;
    
    cp.first = 0;
    cp.second = 0;

    int mx = -(board[0] / 2);
    int x = (board[0] / 2);
    int my = -(board[1] / 2);
    int y = (board[1] / 2);

    for (int i = 0; i < keyinput.size(); i++)
    {
        string temp = keyinput[i];

        if (temp == "right")
        {
            cp.first +=1;
            if (cp.first > x)
            {
                cp.first--;
            }
        }
        else if (temp == "left")
        {
            cp.first -= 1;
            if (cp.first < mx)
            {
                cp.first++;
            }
        }
        else if (temp == "up")
        {
            cp.second += 1;
            if (cp.second > y)
            {
                cp.second--;
            }
        }
        else if (temp == "down")
        {
            cp.second -= 1;
            if (cp.second < my)
            {
                cp.second++;
            }
        }
    }

    answer.push_back(cp.first);
    answer.push_back(cp.second);

    return answer;
}

int main()
{
    solution({ "left", "right", "up", "right", "right" }, { 11,11 });
}