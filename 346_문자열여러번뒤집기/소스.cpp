#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<vector<int>> queries) 
{
    string answer = "";

    for (int i = 0; i < queries.size(); i++)
    {
        string temp = my_string.substr(queries[i][0], queries[i][1] - queries[i][0] + 1);

        reverse(temp.begin(), temp.end());
        int idx = queries[i][0];
        for (int j = 0; j < temp.size(); j++)
        {
            my_string[idx] = temp[j];
            idx++;
        }
    }

    answer = my_string;

    return answer;
}

int main()
{
    solution("rermgorpsam", { {2, 3},{0, 7},{5, 9},{6, 10} });
}