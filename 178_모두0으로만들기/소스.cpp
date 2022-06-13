#include <string>
#include <iostream>
#include <vector>

using namespace std;


long long answer = 0;

// 재귀로 계속 돌리기 !
void DFS(vector<vector<int>> &g, vector<long long> &vll, int current_node, int parent_node)
{
    for (int i = 0; i < g[current_node].size(); i++)
    {
        // 트리 구조에서 부모노드를 제외하고 모두 탐색해야 하기 때문에 아래 조건 필수 
        if (g[current_node][i] != parent_node)
        {
            DFS(g, vll, g[current_node][i], current_node);
        }
    }

    // 재귀가 끝난 이후에는 아래 값을 더해주는 로직이 있어야함 
    vll[parent_node] += vll[current_node];
    answer += abs(vll[current_node]);

}

long long solution(vector<int> a, vector<vector<int>> edges) 
{

    // long long type 변형 
    vector<long long> vll;
    for (int i = 0; i < a.size(); i++)
    {
        vll.push_back((long long)a[i]);
    }

    // graph 만들기 
    vector<vector<int>> graph(a.size());
    for (int i = 0; i < edges.size(); i++)
    {
        // 각 그래프가 벡터에서 양쪽 방향 모두 넣어주기 
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    DFS(graph, vll, 0, 0);

    //root node 가 0이라면 최솟값을 리턴 
    if (vll[0] == 0)
    {
        return answer;
    }
    //아니라면 -1 리턴
    else
    {
        return -1;
    }
}

int main()
{
    vector<vector<int>> a = { {-5, 0, 2, 1, 2} , {0, 1, 0} };
    vector<vector<vector<int>>> edge = { {{0, 1}, {3, 4}, {2, 3}, {0, 3}} , {{0, 1}, {1, 2}} };
    vector<int> dab = { 9,-1 };

    for (int i = 0; i < a.size(); i++)
    {
        long long ans = solution(a[i], edge[i]);
        if (ans == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << ans << " , want = " << dab[i] << endl;
        }
    }
}