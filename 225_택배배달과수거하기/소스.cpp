#include <string>
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;

    stack<int> D;
    stack<int> P;

    // 전체 배달할 갯수와 수거할 갯수를 스택에 넣음 
    for (int i = 0; i < deliveries.size(); i++)
    {
        D.push(deliveries[i]);
        P.push(pickups[i]);
    }
    
    // 스택이 비어있지 않은데 최상위에 0이면 거기를 들리면 안되기 때문에 예외처리함 
    while (!D.empty() && !D.top())
    {
        D.pop();
    }
    while (!P.empty() && !P.top())
    {
        P.pop();
    }

    cout << D.empty() << endl;
    cout << P.empty() << endl;

    // 전체 반복함 수거 배달 하면서 이 while문은 택배차가 나갔다가 들어왔을때 를 1회로 반복한은 루프임 
    while (!(D.empty() && P.empty()))
    {
        // 왕복으로 계산해야하기 때문에 *2를 함 배달할곳이나 수거할곳이나 가장 멀리있는곳을 들려야하기 때문에 max 사용
        answer += max(D.size() * 2, P.size() * 2);

        int maxDCap = 0;
        int maxPCap = 0;

        // 스택이 비어있지 않고 가지고 가려는 박스의 크기가 최대 크기보다 작은경우 
        while (D.empty() == false && maxDCap <= cap)
        {
            // 최대크기보다 작은 경우에 박스를 더해주고 아닌경우에는 top에서 가져간 만큼만 빼준다 
            if (D.top() + maxDCap <= cap)
            {
                maxDCap += D.top();
            }
            else
            {
                D.top() -= (cap - maxDCap);
                break;
            }
            D.pop();
        }

        // 스택이 비어있지 않고 가지고 가려는 박스의 크기가 최대 크기보다 작은경우 
        while (P.empty() == false && maxPCap <= cap)
        {
            // 최대크기보다 작은 경우에 박스를 더해주고 아닌경우에는 top에서 가져간 만큼만 빼준다 
            if (P.top() + maxPCap <= cap)
            {
                maxPCap += P.top();
            }
            else
            {
                P.top() -= (cap - maxPCap);
                break;
            }
            P.pop();
        }
    }
    return answer;
}

int main()
{
    vector<int> c = { 4,2,2,4 };
    vector<int> n = { 5,7,7,4 };
    vector<vector<int>> d = { {1, 0, 3, 1, 2}, {1, 0, 2, 0, 1, 0, 2},{1, 0, 2, 0, 1, 0, 2},{25, 24, 51, 0} };
    vector<vector<int>> p = { {0, 3, 0, 4, 0}, {0, 2, 0, 1, 0, 2, 0},{0, 2, 0, 1, 0, 2, 0},{51, 0, 0, 49} };
    vector<int> dab = { 16,30,30 };

    for (int i = 0; i < d.size(); i++)
    {
        long long re = solution(c[i], n[i], d[i], p[i]);
        if (re == dab[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}