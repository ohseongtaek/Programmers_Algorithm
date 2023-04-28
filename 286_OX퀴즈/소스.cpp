#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) 
{
    vector<string> answer;

    for (int i = 0; i < quiz.size(); i++)
    {
        vector<string> v;
        stringstream ss(quiz[i]);
        string str;
        while (ss>>str)
        {
            v.push_back(str);
        }

        int first = stoi(v[0]);
        string cal = v[1];
        int second = stoi(v[2]);
        int result = stoi(v[4]);

        int ddd = 0;
        bool flag = false;
        if (cal == "-")
        {
            ddd = first - second;
            if (ddd == result)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        else
        {
            ddd = first + second;
            if (ddd == result)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }

        if (flag == true)
        {
            answer.push_back("O");
        }
        else
        {
            answer.push_back("X");
        }
    }
    return answer;
}

int main()
{
    vector<string> v= { "3 - 4 = -3", "5 + 6 = 11"};
    solution(v);
}