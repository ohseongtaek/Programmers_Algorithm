#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) 
{
    string answer = "";

    int idx = myString.rfind(pat);

    answer = myString.substr(0, idx + pat.size());

    return answer;
}