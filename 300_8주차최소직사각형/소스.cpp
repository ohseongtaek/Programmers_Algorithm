#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define FIRST 0
#define SECOND 1

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int first_max = 0;
    int second_max = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        int one = sizes[i][FIRST];
        int two = sizes[i][SECOND];

        if (one < two)
        {
            sizes[i][FIRST] = two;
            sizes[i][SECOND] = one;
        }

        first_max = max(first_max, sizes[i][FIRST]);
        second_max = max(second_max, sizes[i][SECOND]);
    }

    answer = first_max * second_max;

    return answer;
}

int main()
{
    vector<vector<int>> v2 = { {{60, 50},{30, 70},{60, 30},{80, 40}} };
    int dab = solution(v2);

    cout << dab << endl;
}