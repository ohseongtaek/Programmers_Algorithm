#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    vector<pair<int, bool>> vp;
    map<int, bool> m = { {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0} };

    for (int i = 0; i < numbers.size(); i++)
    {
        m[numbers[i]] = 1;
    }

    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == 0)
        {
            answer += i;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> v = { {1,2,3,4,6,7,8,0},{5,8,4,0,6,7,9} };

    for (int i = 0; i < v.size(); i++)
    {
        int result = solution(v[i]);
        cout << result << endl;
    }

    return 0;
}
