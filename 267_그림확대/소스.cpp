#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) 
{
    vector<string> answer;

    for (int i = 0; i < picture.size(); i++)
    {
        string strline = picture[i];
        string linepush = "";
        for (int j = 0; j < strline.size(); j++)
        {
            char strChar = strline[j];

            string tempChar = "";
            for (int xx = 0; xx < k; xx++)
            {
                std::string s;
                s += strChar;
                tempChar += s;
            }
            linepush += tempChar;
        }
        
        for (int j = 0; j < k; j++)
        {
            answer.push_back(linepush);
        }
    }

    return answer;
}

int main()
{
    vector<string> p = { ".xx.xx" };
    solution(p, 2);
}