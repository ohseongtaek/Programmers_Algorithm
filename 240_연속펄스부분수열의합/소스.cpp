#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(vector<int> sequence)
{
	long long answer = 0;

	vector<ll> PP(sequence.size() + 1);
	vector<ll> PM(sequence.size() + 1);

	for (int i = sequence.size() - 1; i >= 0; i--)
	{
		ll MLeft = -sequence[i];
		ll MRight = -sequence[i] + PP[i + 1];
		ll PLeft = sequence[i];
		ll PRight = sequence[i] + PM[i + 1];

		PM[i] = max(MLeft,MRight);
		PP[i] = max(PLeft,PRight);
		answer = max(answer, max(PM[i], PP[i]));
	}
	return answer;
}

int main()
{
    vector<int> v = { 2, 3, -6, 1, 3, -1, 2, 4 };
    int dab = solution(v);
    if (dab == 10)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}


/*
어떤 수열의 연속 부분 수열에 같은 길이의 펄스 수열을 각 원소끼리 곱하여 연속 펄스 부분 수열을 만들려 합니다. 
펄스 수열이란 {1, -1, 1, -1 …} 또는 {-1, 1, -1, 1 …} 과 같이 1 또는 -1로 시작하면서 1과 -1이 번갈아 나오는 수열입니다.

예를 들어 수열 {2, 3, -6, 1, 3, -1, 2, 4}의 연속 부분 수열 {3, -6, 1}에 펄스 수열 {1, -1, 1}을 곱하면 연속 펄스 부분수열은 {3, 6, 1}이 됩니다. 
또 다른 예시로 연속 부분 수열 {3, -1, 2, 4}에 펄스 수열 {-1, 1, -1, 1}을 곱하면 연속 펄스 부분수열은 {-3, -1, -2, 4}이 됩니다.
정수 수열 sequence가 매개변수로 주어질 때, 연속 펄스 부분 수열의 합 중 가장 큰 것을 return 하도록 solution 함수를 완성해주세요.

제한 사항
1 ≤ sequence의 길이 ≤ 500,000
-100,000 ≤ sequence의 원소 ≤ 100,000
sequence의 원소는 정수입니다.
입출력 예
sequence	result
{2, 3, -6, 1, 3, -1, 2, 4}	10
입출력 예 설명
주어진 수열의 연속 부분 수열 {3, -6, 1}에 펄스 수열 {1, -1, 1}을 곱하여 연속 펄스 부분 수열 {3, 6, 1}을 얻을 수 있고 그 합은 10으로서 가장 큽니다.
*/
