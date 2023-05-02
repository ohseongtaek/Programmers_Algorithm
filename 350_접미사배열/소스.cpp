#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> answer;

    string test = "";
    for (int i = my_string.size()-1; i >=0; i--)
    {
        test = my_string[i] + test;
        answer.push_back(test);
    }

    sort(answer.begin(), answer.end());


    return answer;
}