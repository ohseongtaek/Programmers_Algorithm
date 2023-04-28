#include <string>
#include <sstream>
#include <vector>

using namespace std;

int solution(string my_string) 
{
    int answer = 0;

    stringstream ss(my_string);
    string str;
    vector<string> v;
    while (ss >> str)
    {
        v.push_back(str);
    }

    bool current_cal = false;
    bool current_plus = false;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "+" || v[i] == "-")
        {
            current_cal = true;
            if (v[i] == "+")
            {
                current_plus = true;
            }
            else
            {
                current_plus = false;
            }
        }
        else
        {
            if (i == 0)
            {
                sum = stoi(v[i]);
            }
            else
            {
                if (current_cal == true)
                {
                    if (current_plus == true)
                    {
                        sum += stoi(v[i]);
                    }
                    else
                    {
                        sum -= stoi(v[i]);
                    }
                    current_cal = false;
                }
            }
        }
    }

    answer = sum;
    

    return answer;
}