#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string) 
{
    string answer = my_string;

    reverse(answer.begin(), answer.end());

    return answer;
}