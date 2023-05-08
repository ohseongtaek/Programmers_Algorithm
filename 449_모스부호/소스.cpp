#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string arr[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",
                ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                "...","-","..-","...-",".--","-..-","-.--","--.." };

string solution(string letter) 
{
    map<string, char> mp;
    string answer = "";
    string str = "";
    stringstream ss(letter);
    char c = 'a';

    for (int i = 0; i < 26; i++)
    {
        mp[arr[i]] = c + i;
    }
    
    while (ss >> str) 
    {
        answer += mp[str];
    }

    return answer;
}