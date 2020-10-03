#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> node;

// sort function
bool comp(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

// Retrun Root node function
int find(int RetRoot) {
    if (RetRoot == node[RetRoot]) {
        return RetRoot;
    }
    else {
        int temp = find(node[RetRoot]);
        node[RetRoot] = temp;
        return temp;
    }
}


// Changed Root node
void Union(int start, int end) {
    start = find(start);
    end = find(end);

    if (start != end) {
        node[end] = start;
    }
}

// 크루스칼 알고리즘을 선택 후 해결 그리고 사이클에 대한 해결을 위해 union-find 알고리즘 이용

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), comp);

    /* debug code
    for(int i=0; i<costs.size(); i++){
        cout << costs[i][0] << " " << costs[i][1] << " " << costs[i][2] << endl;
    }
    */

    // self parent node
    for (int i = 0; i < n; i++) {
        node.push_back(i);
    }

    // using union - find algorithm
    for (int i = 0; i < costs.size(); i++) {
        int start = find(costs[i][0]);
        int end = find(costs[i][1]);
        int value = costs[i][2];

        if (start != end) {
            //cout << "what i ? " << i << endl;
            //cout << "value = ? " << value << endl;
            Union(start, end);
            answer += value;
        }

    }
    return answer;
}


int main() {
    int n = 4;
    vector<vector<int>> v = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    cout << "solution ? " << solution(n, v) << endl;
    cout << endl;
}