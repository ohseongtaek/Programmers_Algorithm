#include <string>
#include <iostream>
#include <vector>

using namespace std;

int answer = 1;

typedef enum _animal
{
    E_SHEEP = 0,
    E_WOLF = 1
}ANIMAL;

void DFS(int idx, int wolf, int sheep, vector<int> node, vector<int> info, vector<vector<int>> allnode)
{
    bool ani = info[idx];
    if (ani == E_SHEEP)
    {
        sheep++;
    }
    else
    {
        wolf++;
    }
    answer = max(answer, sheep);

    //answer = max(answer, g_sheep);

    if (wolf >= sheep)
    {
        return;
    }

    for (int i = 0; i < node.size(); i++)
    {
        vector<int> nextNode = node;
        nextNode.erase(nextNode.begin() + i);
        for (int j = 0; j < allnode[node[i]].size(); j++)
        {
            nextNode.push_back(allnode[node[i]][j]);
        }
        DFS(node[i], wolf, sheep, nextNode, info, allnode);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) 
{
    vector<vector<int>> vec(info.size());
    vector<int> node;

    for (int i = 0; i < edges.size(); i++)
    {
        vec[edges[i][0]].push_back(edges[i][1]);
    }

    // 0번 노드 연결 
    for (int i = 0; i < vec[0].size(); i++)
    {
        node.push_back(vec[0][i]);
    }


    DFS(0, 0, 0, node, info, vec);

    return answer;
}

int main()
{

    vector<vector<int>> info = { {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, 
                                 {0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0} };
    vector<vector<vector<int>>> edge = { {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}},
                                         {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10}} };
    vector<int> dab = { 5, 5 };

    for (int i = 0; i < info.size(); i++)
    {
        int answer = solution(info[i], edge[i]);
        if (answer == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << answer << ", [want] = " << dab[i] << endl;
        }
    }

}

//Programmers_Level3_Solution