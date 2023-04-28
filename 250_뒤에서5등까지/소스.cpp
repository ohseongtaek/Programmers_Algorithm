#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer;

    sort(num_list.begin(), num_list.end());

    for (int i = 0; i < 5; i++)
    {
        answer.push_back(num_list[i]);
    }

    return answer;
}

int main()
{
    vector<int> v = { 12, 4, 15, 46, 38, 1, 14 };
    vector<int> d = { 1, 4, 12, 14, 15 };

    vector<int> ans = solution(v);
}