#include <vector>
#include <iostream>

using namespace std;

// n => 거점의 갯수 
// m => 도로의 갯수
// edge_list => 연결된 도로 정보 
// k => 시간대 별로 보내오는 거점 정보의 총 갯수 
// gps_log => 머물렀던 거점의 정보 
// 올바른 경로로 수정하는 것이 불가능할 경우 -1을 리턴

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) 
{
    int answer = -1;

    // 도로의 벡터와 DP 의 벡터 초기화 
    vector<vector<int>> edge(n + 1);
    vector<vector<int>> DP(k, vector<int>(n + 1, 2e9));

    // 각 거점간의 연결 
    for (int i = 0; i < edge_list.size(); i++)
    {
        edge[edge_list[i][0]].push_back(edge_list[i][1]);
        edge[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    // 0번째에서 gps_log[0] 까지 가는데 수정한 횟수 0 => 처음에 위치한곳은 수정할 이유가 없기 때문에 0으로 초기화 시킴 
    DP[0][gps_log[0]] = 0;

    // 시간대 별로 거점의 수정을 알아야 하기 때문에 가장 큰 for문에서 돌림 
    for (int time = 1; time < k; time++)
    {
        for (int pos = 1; pos <= n; pos++)
        {
            // 간선이 연결되어 있지 않는 경우 그냥 continue
            if (DP[time - 1][pos] == 2e9)
            {
                continue;
            }

            // 간선이 연결된 크기만큼 반복 시작
            for (int idx = 0; idx < edge[pos].size(); idx++)
            {
                int next_pos = edge[pos][idx];
                int changed = 0;

                // 간선에서 연결이 가능하도록 변경하기 
                if (gps_log[time] != next_pos)
                {
                    changed++;
                }

                // 기존 값과 변경한 값중 작은값을 다음 DP에 넣어서 계산함 
                DP[time][next_pos] = min(DP[time][next_pos], DP[time - 1][pos] + changed);
            }
        }
    }

    // 도착지점까지 왔을때 2e9 보다 작다면 도착이 가능한 것으로 값 리턴 
    if (DP[k - 1][gps_log[k - 1]] < 2e9)
    {
        answer = DP[k - 1][gps_log[k - 1]];
    }

    return answer;
}

int main()
{
    vector<int> n = { 7,7 };
    vector<int> m = { 10,10 };
    vector<vector<vector<int>>> el = { {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}} ,
                                       {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}} };
    vector<int> k = { 6,6 };
    vector<vector<int>> gl = { {1, 2, 3, 3, 6, 7} , 
                               {1, 2, 4, 6, 5, 7} };

    vector<int> dab = { 1, 0 };

    for (int i = 0; i < dab.size(); i++)
    {
        int answer = solution(n[i], m[i], el[i], k[i], gl[i]);

        if (answer == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << answer << " , want = " << dab[i] << endl;
        }
    }

    return 0;
}
