#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void refunc(int first, int num, vector<vector<int>>& computers, vector<bool>& flag) {
    // 일단 들어오면 무조건 해당 위치는 true로 변경 이게 변경하면 해당 네트워크는 같은 대역이라 판단후 삭제되는것  
    flag[first] = true;

    // 이후 넘어온 값에 대해 각각의 원소를 재귀 
    for (int i = 0; i < num; i++) {
        if (computers[first][i] && !flag[i]) {
            cout << "refunc i ? " << i << endl;
            refunc(i, num, computers, flag);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    //n 의 크기를 가진 bool 의 벡터 생성 
    vector<bool> flag(n, false);

    // for로 n만큼 반복해 만약 flag의 값이 false 이면 재귀함수 시작 및 answer ++ 
    // 여기서 재귀함수는 flag값을 가지고 같은 네트워크 대역을 지우는 중요한 역할 
    for (int i = 0; i < n; i++) {
        if (flag[i] == false) {
            refunc(i, n, computers, flag);
            answer++;
        }
    }

    return answer;
}

int main() {
    int num = 3;
    vector<vector<int>> vv = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    cout << solution(num, vv) << endl;;
}