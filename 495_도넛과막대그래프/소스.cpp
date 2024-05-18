#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges) 
{
    // 노드, (나가는 간선 수, 들어오는 간선 수)
    unordered_map<int, pair<int, int>> nodeCnt; 

    vector<int> answer = { 0, 0, 0, 0 };

    for (vector<int> edge : edges) 
    {
        int a = edge[0];
        int b = edge[1];

        if (!nodeCnt.count(a)) 
        {
            nodeCnt[a] = { 0, 0 };
        }
        if (!nodeCnt.count(b)) 
        {
            nodeCnt[b] = { 0, 0 };
        }

        nodeCnt[a].first++;
        nodeCnt[b].second++;
    }

    int cnts[2];
    for (auto it : nodeCnt) 
    {
        cnts[0] = it.second.first;
        cnts[1] = it.second.second;

        if (cnts[1] == 0 && cnts[0] >= 2) 
        {
            answer[0] = it.first;
        }
        else if (cnts[0] == 0 && cnts[1] > 0)
        {
            answer[2]++;
        }
        else if (cnts[0] >= 2 && cnts[1] >= 2) 
        {
            answer[3]++;
        }
    }

    answer[1] = nodeCnt[answer[0]].first - answer[2] - answer[3];

    return answer;
}

int main()
{
    vector<vector<vector<int>>> edges = { {{2, 3}, {4, 3}, {1, 1}, {2, 1}} ,
                                          {{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}} };
    vector<vector<int>> v = { {2, 1, 1, 0},
                              {4, 0, 1, 2} };

    for (int i = 0; i < edges.size(); i++)
    {
        vector<int> dab = solution(edges[i]);

        bool flag = false;
        for (int j = 0; j < dab.size(); j++)
        {
            if (v[i][j] != dab[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "good" << endl;
        }
    }
}