#include <string>
#include <vector>

using namespace std;

int solution(string binomial) 
{
    int answer = 0;

    vector<string> v;
    string test = "";
    for (int i = 0; i < binomial.size(); i++)
    {
        if (binomial[i] == ' ')
        {
            v.push_back(test);
            test = "";
        }
        else
        {
            test += binomial[i];
        }
    }

    v.push_back(test);

    int a = stoi(v[0]);
    string c = v[1];
    int b = stoi(v[2]);

    if (c == "+")
    {
        answer = a + b;
    }
    else if(c=="*")
    {
        answer = a * b;
    }
    else
    {
        answer = a - b;
    }



    return answer;
}

int main()
{
    solution("43 + 12");
}