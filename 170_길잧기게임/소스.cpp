#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TREE
{
    int iNodeCnt;
    int x;
    int y;
    TREE* left;     // 현재 노드의 왼쪽 자식 정보 
    TREE* right;    // 현재 노드의 오른쪽 자식 정보 
};

bool compare(TREE a, TREE b)
{
    if (a.y >= b.y)
    {
        if (a.y == b.y)
        {
            if (a.x < b.x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void makeTree(TREE* rootNode, TREE* childNode)
{
    // x 좌표 기준으로 왼쪽 오른쪽 채우기 
    // 왼쪽 채우기 
    if (rootNode->x > childNode->x)
    {
        // 왼쪽 노드가 비어있는 경우  넣기 
        if (rootNode->left == NULL)
        {
            rootNode->left = childNode;
            return;
        }
        // 아닌 경우 왼쪽에 있는 노드가 루트노드가 되며 들어가게 만들기 
        makeTree(rootNode->left, childNode);
    }

    // 오른쪽 채우기 
    else
    {
        // 오른쪽 노드가 비어있는 경우 그냥 넣기 
        if (rootNode->right == NULL)
        {
            rootNode->right = childNode;
            return;
        }
        // 아닌 경우 오른쪽 에 있는 노드에다가 넣기 
        makeTree(rootNode->right, childNode);
    }
}

void preorder(TREE* rootNode, vector<int>& pre)
{
    // 노드가 없는 경우는 리턴
    if (rootNode == NULL)
    {
        return;
    }
    else
    {
        pre.push_back(rootNode->iNodeCnt);
        // 재귀로 왼쪽꺼 무조건 먼저 탐색후 오른쪽꺼 탐색 
        preorder(rootNode->left, pre);
        preorder(rootNode->right, pre);

    }
}

void postorder(TREE* rootNode, vector<int>& post)
{
    // 노드가 없는 경우는 리턴
    if (rootNode == NULL)
    {
        return;
    }
    else
    {
        // 재귀로 왼쪽꺼 무조건 먼저 탐색후 오른쪽꺼 탐색 
        postorder(rootNode->left, post);
        postorder(rootNode->right, post);
        post.push_back(rootNode->iNodeCnt);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    // 정보 삽입 
    vector<TREE> vecTree;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        TREE tr;
        tr.x = nodeinfo[i][0];
        tr.y = nodeinfo[i][1];
        tr.iNodeCnt = i + 1;
        tr.left = NULL;
        tr.right = NULL;
        vecTree.push_back(tr);
    }

    // 정렬 (y좌표 가장 큰게 루트노드 , x좌표 작은게 왼쪽노드 이런식)
    sort(vecTree.begin(), vecTree.end(), compare);

    // Tree 의 왼쪽 오른쪽 노드 채워주기 
    TREE* rootNode = &vecTree[0];
    for (int i = 1; i < vecTree.size(); i++)
    {
        makeTree(rootNode, &vecTree[i]);
    }


    // 전위순회 
    vector<int> pre;
    preorder(rootNode, pre);

    // 후위순회 
    vector<int> post;
    postorder(rootNode, post);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

int main()
{
    vector<vector<int>> v = { {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} };
    vector<vector<int>> ans = { {7, 4, 6, 9, 1, 8, 5, 2, 3}, {9, 6, 5, 8, 1, 4, 3, 2, 7} };
    vector<vector<int>> dab;

    dab = solution(v);

    for (int i = 0; i < dab.size(); i++)
    {
        for (int j = 0; j < dab[i].size(); j++)
        {
            cout << dab[i][j] << " ";
        }
        cout << endl;
    }
}

/*

곤경에 빠진 카카오 프렌즈를 위해 이진트리를 구성하는 노드들의 좌표가 담긴 배열 nodeinfo가 매개변수로 주어질 때,
노드들로 구성된 이진트리를 전위 순회, 후위 순회한 결과를 2차원 배열에 순서대로 담아 return 하도록 solution 함수를 완성하자.

제한사항
nodeinfo는 이진트리를 구성하는 각 노드의 좌표가 1번 노드부터 순서대로 들어있는 2차원 배열이다.
nodeinfo의 길이는 1 이상 10, 000 이하이다.
nodeinfo{i} 는 i + 1번 노드의 좌표이며, {x축 좌표, y축 좌표} 순으로 들어있다.
모든 노드의 좌표 값은 0 이상 100, 000 이하인 정수이다.
트리의 깊이가 1, 000 이하인 경우만 입력으로 주어진다.
모든 노드의 좌표는 문제에 주어진 규칙을 따르며, 잘못된 노드 위치가 주어지는 경우는 없다.



*/