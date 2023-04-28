#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string) 
{
    string answer = "";

    for (int i = 0; i < my_string.size(); i++)
    {
        char test = tolower(my_string[i]);
        my_string[i] = test;
    }

    sort(my_string.begin(), my_string.end());

    answer = my_string;
    return answer;
}