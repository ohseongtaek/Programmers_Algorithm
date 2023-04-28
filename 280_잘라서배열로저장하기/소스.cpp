#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) 
{
    vector<string> answer;
    int ms = my_str.size() / n;
    for (int i = 0; i < ms; i++)
    {
        answer.push_back(my_str.substr(0, n));
        my_str = my_str.substr(n, my_str.size());
    }

    if (my_str != "")
    {
        answer.push_back(my_str);
    }

    return answer;
}

int main()
{
    solution("abc1Addfggg4556b", 6);
}