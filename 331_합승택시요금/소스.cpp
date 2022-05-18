#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 참조 https://ssungkang.tistory.com/entry/Algorithm-%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C-%EC%99%80%EC%83%ACFloyd-Warshall-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
// 지점의 개수 n, 출발지점을 나타내는 s, A의 도착지점을 나타내는 a, B의 도착지점을 나타내는 b,

int Min(int A, int B) 
{
    if (A < B)
    {
        return A;
    }
    
    return B;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int init_num = 10000000;
    int answer = init_num;
    
    vector<vector<int>> vecTwo(n + 1, vector<int>(n + 1, init_num));

    // 배열 초기화 
    for (int i = 0; i < fares.size(); i++)
    {
        int Start = fares[i][0];
        int End = fares[i][1];
        int Money = fares[i][2];

        vecTwo[Start][End] = Money;
        vecTwo[End][Start] = Money;
    }

    // 스스로에게 가는 배열은 모두 0
    for (int i = 0; i <= n; i++)
    {
        vecTwo[i][i] = 0;
    }

    // 플로이드와샬 알고리즘
    // 특정 정점에서 다른 정점의 최소비용 => 다익스트라 , 벨만포드 알고리즘 
    // 모든 정점의 최소비용 
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j || i == k || k == j)
                {
                    continue;
                }
                if (vecTwo[i][k] != init_num && vecTwo[k][j] != init_num)
                {
                    vecTwo[i][j] = Min(vecTwo[i][j], vecTwo[i][k] + vecTwo[k][j]);
                }
            }
        }
    }
#ifdef _DEBUG
    for (int i = 0; i < vecTwo.size(); i++)
    {
        for(int j=0; j< vecTwo[i].size(); j++)
        {
            cout << vecTwo[i][j] << " ";
        }
        cout << endl;
    }
#endif

    for (int i = 1; i <= n; i++)
    {
        if (vecTwo[s][i] != init_num && vecTwo[i][a] != init_num && vecTwo[i][b] != init_num)
        {
            answer = Min(answer, vecTwo[s][i] + vecTwo[i][a] + vecTwo[i][b]);
        }
    }

    return answer;
}

int main()
{
    vector<int> n = { 6,7,6 };
    vector<int> s = { 4,3,4 };
    vector<int> a = { 6,4,5 };
    vector<int> b = { 2,1,6 };

    vector<vector<vector<int>>> far = { {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}, 
                                        {{5, 7, 9},  {4, 6, 4},  {3, 6, 1}, {3, 2, 3},  {2, 1, 6}}, 
                                        {{2, 6, 6},  {6, 3, 7},  {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}} };
    vector<int> answer = { 82,14,18 };

    for (int i = 0; i < n.size(); i++)
    {
        int test = solution(n[i], s[i], a[i], b[i], far[i]);
        if (answer[i] == test)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << test << ", [want] = " << answer[i] << endl;
        }
    }
    
}