#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = std::numeric_limits<int>::max();

bool check(int idx, int temp, int t1, int t2, std::vector<int>& onboard) 
{
    return !(onboard[idx] && !(t1 <= temp && temp <= t2));
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) 
{
    temperature += 10;
    t1 += 10;
    t2 += 10;
    int length = onboard.size();
    std::vector<std::vector<int>> temp_dp(length, std::vector<int>(51, MAX));
    temp_dp[0][temperature] = 0;

    for (int i = 0; i < length - 1; ++i) 
    {
        for (int j = 0; j < 51; ++j) 
        {
            if (temp_dp[i][j] == MAX) 
            {
                continue;
            }

            // Off case:
            int temp;
            if (j < temperature) 
            {
                temp = j + 1;
            }
            else if (j > temperature) 
            {
                temp = j - 1;
            }
            else 
            {
                temp = j;
            }

            if (check(i + 1, temp, t1, t2, onboard)) 
            {
                temp_dp[i + 1][temp] = std::min(temp_dp[i + 1][temp], temp_dp[i][j]);
            }

            // On case:
            std::vector<std::pair<int, int>> temp_cost_pairs = { {j + 1, a}, {j - 1, a}, {j, b} };
            for (const auto& pair : temp_cost_pairs) 
            {
                int temp = pair.first;
                int cost = pair.second;
                if (!check(i + 1, temp, t1, t2, onboard) || !(temp > -1 && temp < 51)) 
                {
                    continue;
                }
                temp_dp[i + 1][temp] = std::min(temp_dp[i + 1][temp], temp_dp[i][j] + cost);
            }
        }
    }

    int min_cost = MAX;
    for (int i = 0; i < 51; ++i) 
    {
        min_cost = std::min(min_cost, temp_dp[length - 1][i]);
    }

    return min_cost;
}


int main()
{
    vector<int> temp = { 28,-10,11,11 };
    vector<int> t1 = { 18,-5,8,8 };
    vector<int> t2 = { 26,5,10,10 };
    vector<int> a = { 10,5,10,10 };
    vector<int> b = { 8,1,1,100 };
    vector<vector<int>> v = { {0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1} };
    vector<int> result = { 40,25,20,60 };

    for (int i = 0; i < temp.size(); i++)
    {
        int dab = solution(temp[i], t1[i], t2[i], a[i], b[i], v[i]);
        if (result[i] == dab)
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }
}