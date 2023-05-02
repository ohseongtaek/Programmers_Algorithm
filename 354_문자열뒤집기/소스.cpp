#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) 
{
    string answer = "";

    string test = my_string.substr(s, e - s + 1);

    reverse(test.begin(), test.end());

    int idx = s;
    for (int i = 0; i < test.size(); i++)
    {
        my_string[idx] = test[i];
        idx++;
    }

    answer = my_string;

    return answer;
}

int main()
{
    solution("Progra21Sremm3", 6, 12);
}