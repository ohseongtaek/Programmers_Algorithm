#include <string>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

#define NOT_VISIT -1

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size(), NOT_VISIT);
    stack<pair<int, int>> sp;

    for (int i = 0; i < numbers.size(); i++)
    {
        while (true)
        {
            if (sp.empty() == true)
            {
                break;
            }
            else
            {
                auto spTop = sp.top();

                if (spTop.first >= numbers[i])
                {
                    break;
                }
                else
                {
                    answer[spTop.second] = numbers[i];
                    sp.pop();
                }
            }
        }
        sp.push(make_pair(numbers[i], i));
    }

    return answer;
}

int main()
{
    vector<vector<int>> vv = { {2, 3, 3, 5}, {9, 1, 5, 3, 6, 2} };
    vector<vector<int>> an = { {3, 5, 5, -1},{-1, 5, 6, 6, -1, -1} };

    for (int i = 0; i < vv.size(); i++)
    {
        vector<int> r = solution(vv[i]);

        bool flag = false;
        for (int j = 0; j < r.size(); j++)
        {
            if (r[j] != an[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "good" << endl;
        }
    }
}

/*
정수로 이루어진 배열 numbers가 있습니다. 배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.
정수 배열 numbers가 매개변수로 주어질 때, 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요. 단, 뒷 큰수가 존재하지 않는 원소는 -1을 담습니다.

제한사항
4 ≤ numbers의 길이 ≤ 1,000,000
1 ≤ numbers{i} ≤ 1,000,000
입출력 예
numbers	result
	
입출력 예 설명
입출력 예 #1
2의 뒷 큰수는 3입니다. 첫 번째 3의 뒷 큰수는 5입니다. 두 번째 3 또한 마찬가지입니다. 5는 뒷 큰수가 없으므로 -1입니다. 위 수들을 차례대로 배열에 담으면 {3, 5, 5, -1}이 됩니다.

입출력 예 #2
9는 뒷 큰수가 없으므로 -1입니다. 1의 뒷 큰수는 5이며, 5와 3의 뒷 큰수는 6입니다. 6과 2는 뒷 큰수가 없으므로 -1입니다. 위 수들을 차례대로 배열에 담으면 {-1, 5, 6, 6, -1, -1}이 됩니다.
*/