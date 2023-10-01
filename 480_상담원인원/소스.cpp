#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include <vector>
#include <Windows.h>
using namespace std;

const int MAX = std::numeric_limits<int>::max();

std::map<int, std::vector<std::pair<int, int>>> req_dict;
std::vector<int> type_list;
int type_num;

int calculate(int n, const std::vector<std::pair<int, int>>& req_list) 
{
    int result = 0;
    std::vector<int> mento_list(n + 1, 0);
    for (const auto& req : req_list) 
    {
        int best_mento = -1, best_time = MAX;
        for (int i = 0; i <= n; ++i) 
        {
            if (best_time > mento_list[i]) 
            {
                best_mento = i;
                best_time = mento_list[i];
            }
        }
        result += std::max(0, best_time - req.first);
        mento_list[best_mento] = std::max(req.first, best_time) + req.second;
    }
    return result;
}

int combs(int left, int idx)
{
    if (idx == type_num || left == 0) 
    {
        int result = 0;
        for (int i = 0; i < type_num; ++i) 
        {
            result += calculate(type_list[i], req_dict[i]);
        }
        return result;
    }

    int result = MAX;
    for (int i = 0; i <= left; ++i) 
    {
        type_list[idx] = i;
        result = std::min(result, combs(left - i, idx + 1));
    }
    type_list[idx] = 0;
    return result;
}

int solution(int k, int n, std::vector<std::vector<int>> reqs)
{
    type_num = k;
    n -= k;
    req_dict.clear();
    type_list.resize(k, 0);

    for (const auto& req : reqs) 
    {
        int c = req[2] - 1;
        req_dict[c].push_back({ req[0], req[1] });
    }

    return combs(n, 0);
}

int main()
{
    vector<int> k = { 3,2 };
    vector<int> n = { 5,3 };
    vector<vector<vector<int>>> req = { {{10, 60, 1}, {15, 100, 3}, {20, 30, 1}, {30, 50, 3}, {50, 40, 1}, {60, 30, 2}, {65, 30, 1}, {70, 100, 2}},
        {{5, 55, 2}, {10, 90, 2}, {20, 40, 2}, {50, 45, 2}, {100, 50, 2}} };
    vector<int> dab = { 25,90 };

    for (int i = 0; i < k.size(); i++)
    {
        int result = solution(k[i], n[i], req[i]);
        if (result == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
        }
    }
}