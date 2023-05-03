#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) 
{
    int answer = 0;

    map<int, int> m;
    map<int, int>::iterator iter;

    for (int i = 0; i < lines.size(); i++)
    {
        int s = lines[i][0];
        int e = lines[i][1];

        for (int j = s; j < e; j++)
        {
            m[j]++;
        }
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second >= 2)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    solution({ {{0, 5}, {3, 9}, {1, 10}} });
}