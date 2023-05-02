#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";

    for (int j = 0; j < indices.size(); j++)
    {
        my_string[indices[j]] = '_';
    }

    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] != '_')
        {
            answer += my_string[i];
        }
    }


    return answer;
}