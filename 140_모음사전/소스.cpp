#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

vector<string> idx = { "A","E","I","O","U"};
map<string, int> m;
int cnt = 1;
void LoopFunc(string word)
{
    if (word.length() > 5)
    {
        return;
    }

    m[word] = cnt++;

    for (int i = 0; i < idx.size(); i++)
    {
        LoopFunc(word + idx[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    int cnt = 1;

    for (int i = 0; i < idx.size(); i++)
    {
        LoopFunc(idx[i]);
    }

    return m[word];
}

int main()
{
    string a = "AAAAE";
    int dab = solution(a);
    cout << dab << endl;
}