#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) 
{
    string answer = "";

    string id = id_pw[0];
    string pw = id_pw[1];

    int check = 0;

    for (int i = 0; i < db.size(); i++)
    {
        if (id == db[i][0] && pw == db[i][1])
        {
            answer = "login";
            check = 4;
        }
        else if (id == db[i][0] && pw != db[i][1])
        {
            if (check == 4)
            {

            }
            else
            {
                answer = "wrong pw";
                check = 3;
            }
        }
        else if (id != db[i][0] && pw != db[i][1])
        {
            if (check >= 3)
            {

            }
            else
            {
                answer = "fail";
                check = 2;
            }
        }
    }

    return answer;
}