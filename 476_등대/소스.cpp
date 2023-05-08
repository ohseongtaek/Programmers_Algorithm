#include <string>
#include <vector>

using namespace std;

bool onl[100001] = { 0 };

void DFS(int node, int parent, vector<vector<int>>& info, int &answer) 
{
    for (int i = 0; i < info[node].size(); i++) 
    {
        if (info[node][i] != parent) 
        {
            DFS(info[node][i], node, info, answer);

            if (!onl[info[node][i]] && !onl[node]) 
            {
                onl[node] = true;
                answer++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) 
{
    vector<vector<int>> info(n + 1);
    int answer = 0;
    for (int i = 0; i < lighthouse.size(); i++) 
    {
        info[lighthouse[i][0]].push_back(lighthouse[i][1]);
        info[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    DFS(1, 1, info, answer);
    return answer;
}