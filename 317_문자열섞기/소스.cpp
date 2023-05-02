#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";

    char test[200] = { 0, };
    int idx = 0;

    for (int i = 0; i < str1.size(); i++)
    {
        test[idx] = str1[i];
        test[idx + 1] = str2[i];
        idx += 2;
    }
    string ttt(test);
    
    answer = ttt;

    return answer;
}