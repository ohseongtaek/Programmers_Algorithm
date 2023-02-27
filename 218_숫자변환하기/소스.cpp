#include <string>
#include <queue>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

int solution(int x, int y, int n)
{
	if (x == y)
	{
		return 0;
	}

	queue<pair<int, int>> qp;
	set<int> s;
	set<int>::iterator iter;
	int answer = 0;

	qp.push(make_pair(x, 0));

	while (!qp.empty())
	{
		auto aqp = qp.front();
		qp.pop();

		// 값이 같은 경우 리턴 
		if (aqp.first == y)
		{
			answer = aqp.second;
			break;
		}
		// 값이 다른경우 즉 x가 y값에 도달하지 못한경우 
		else if(aqp.first < y)
		{
			int cal1 = aqp.first + n;
			int cal2 = aqp.first * 2;
			int cal3 = aqp.first * 3;

			iter = s.find(cal1);
			if (iter == s.end())
			{
				s.insert(cal1);
				qp.push(make_pair(cal1, aqp.second + 1));
			}
			iter = s.find(cal2);
			if (iter == s.end())
			{
				s.insert(cal2);
				qp.push(make_pair(cal2, aqp.second + 1));
			}
			iter = s.find(cal3);
			if (iter == s.end())
			{
				s.insert(cal3);
				qp.push(make_pair(cal3, aqp.second + 1));
			}
		}
	}

	if (answer == 0)
	{
		answer = -1;
	}

	return answer;
}

int main()
{
	vector<int> x = { 10, 10, 2 };
	vector<int> y = { 40, 40, 5 };
	vector<int> n = { 5, 30, 4 };
	vector<int> ans = { 2,1,-1 };

	for (int i = 0; i < x.size(); i++)
	{
		int r = solution(x[i],y[i],n[i]);

		bool flag = false;

		if (r != ans[i])
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
자연수 x를 y로 변환하려고 합니다. 사용할 수 있는 연산은 다음과 같습니다.

x에 n을 더합니다
x에 2를 곱합니다.
x에 3을 곱합니다.
자연수 x, y, n이 매개변수로 주어질 때, x를 y로 변환하기 위해 필요한 최소 연산 횟수를 return하도록 solution 함수를 완성해주세요. 이때 x를 y로 만들 수 없다면 -1을 return 해주세요.

제한사항
1 ≤ x ≤ y ≤ 1,000,000
1 ≤ n < y
입출력 예
x	y	n	result
10	40	5	2
10	40	30	1
2	5	4	-1
입출력 예 설명
입출력 예 #1
x에 2를 2번 곱하면 40이 되고 이때가 최소 횟수입니다.

입출력 예 #2
x에 n인 30을 1번 더하면 40이 되고 이때가 최소 횟수입니다.

입출력 예 #3
x를 y로 변환할 수 없기 때문에 -1을 return합니다.


*/