#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) 
{
    // 값이 같은경우 앞에거 부터 
    if ((a.second - a.first) == (b.second - b.first))
    {
        return a.first < b.first;
    }
    // 값이 다른경우 작은거 부터 
    return (a.second - a.first) < (b.second - b.first);
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int, int>> vp;

    int left = 0;
    int right = 0;
    int sum = 0;

    while (left < sequence.size())
    {
        // 합이 같거나 큰 경우 
        if (sum >= k || right >= sequence.size())
        {
            sum = sum - sequence[left];
            left++;
        }
        else
        {
            sum = sum + sequence[right];
            right++;
        }

        if (sum == k)
        {
            vp.push_back(make_pair(left, right - 1));
        }
    }

    sort(vp.begin(), vp.end(), comp);

    answer.push_back(vp[0].first);
    answer.push_back(vp[0].second);

    return answer;
}


int main()
{
    vector<vector<int>> s = { { 1, 2, 3, 4, 5 },
                               {1, 1, 1, 2, 3, 4, 5},
                               {2, 2, 2, 2, 2} };
    vector<int> k = { 7,5,6 };
	vector<vector<int>> dab = { {2, 3},
	                            {6, 6},
	                            {0, 2}};
    
    for (int i = 0; i < dab.size(); i++)
    {
        bool flag = false;
        vector<int> a = solution(s[i], k[i]);
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != dab[i][j])
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
        {
            cout << "error " << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
}
/*
* 수열을 나타내는 정수 배열 sequence와 부분 수열의 합을 나타내는 정수 k가 매개변수로 주어질 때, 위 조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return 하는 solution 함수를 완성해주세요. 이때 수열의 인덱스는 0부터 시작합니다.

제한사항
5 ≤ sequence의 길이 ≤ 1,000,000
1 ≤ sequence의 원소 ≤ 1,000
sequence는 비내림차순으로 정렬되어 있습니다.
5 ≤ k ≤ 1,000,000,000
k는 항상 sequence의 부분 수열로 만들 수 있는 값입니다.
입출력 예
sequence	k	result

입출력 예 설명
입출력 예 #1

{1, 2, 3, 4, 5}에서 합이 7인 연속된 부분 수열은 {3, 4}뿐이므로 해당 수열의 시작 인덱스인 2와 마지막 인덱스 3을 배열에 담아 {2, 3}을 반환합니다.

입출력 예 #2

{1, 1, 1, 2, 3, 4, 5}에서 합이 5인 연속된 부분 수열은 {1, 1, 1, 2}, {2, 3}, {5}가 있습니다. 이 중 {5}의 길이가 제일 짧으므로 해당 수열의 시작 인덱스와 마지막 인덱스를 담은 {6, 6}을 반환합니다.

입출력 예 #3

{2, 2, 2, 2, 2}에서 합이 6인 연속된 부분 수열은 {2, 2, 2}로 3가지 경우가 있는데, 길이가 짧은 수열이 여러 개인 경우 앞쪽에 나온 수열을 찾으므로 {0, 2}를 반환합니다.
*/