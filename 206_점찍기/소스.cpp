#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/* time out 
long long solution(int k, int d) 
{
	long long answer = 0;
	
	for (int i = 0; i <= d; i += k)
	{
		for (int j = 0; j <= d; j += k)
		{
			if (i == 0 && j == 0)
			{
				answer++;
			}
			else
			{
				double len = sqrt(pow(i, 2) + pow(j, 2));
				if (len > d)
				{
					break;
				}
				else
				{
					answer++;
				}
			}
		}
	}
	return answer;
}
*/

long long getCountY(int x, int d)
{
	//x2+y2<=d2 ==> y2 <= d2-x2
	long long left = sqrt((pow(d, 2) - pow(x, 2)));
	return left;
}

long long solution(int k, int d)
{
	long long answer = 0;
	
	// 원의 방정식 이용 
	for (int i = 0; i <= d; i += k)
	{
		long long yCnt = getCountY(i, d);
		long long kyCnt = yCnt / k;
		long long kyfCnt = floor(kyCnt);
		answer += kyfCnt + 1;
	}

	return answer;
}

int main()
{
	vector<int> k = { 2,1 };
	vector<int> d = { 4,5 };
	vector<int> ans = { 6,26 };

	for (int i = 0; i < k.size(); i++)
	{
		long long a = solution(k[i], d[i]);
		if (a == ans[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error" << endl;
		}
	}
}








/*
좌표평면을 좋아하는 진수는 x축과 y축이 직교하는 2차원 좌표평면에 점을 찍으면서 놀고 있습니다.진수는 두 양의 정수 k, d가 주어질 때 다음과 같이 점을 찍으려 합니다.

원점(0, 0)으로부터 x축 방향으로 a*k(a = 0, 1, 2, 3 ...), y축 방향으로 b*k(b = 0, 1, 2, 3 ...)만큼 떨어진 위치에 점을 찍습니다.
원점과 거리가 d를 넘는 위치에는 점을 찍지 않습니다.
예를 들어, k가 2, d가 4인 경우에는(0, 0), (0, 2), (0, 4), (2, 0), (2, 2), (4, 0) 위치에 점을 찍어 총 6개의 점을 찍습니다.

정수 k와 원점과의 거리를 나타내는 정수 d가 주어졌을 때, 점이 총 몇 개 찍히는지 return 하는 solution 함수를 완성하세요.

제한사항
1 ≤ k ≤ 1, 000, 000
1 ≤ d ≤ 1, 000, 000
입출력 예
k	d	result
2	4	6
1	5	26
입출력 예 설명
입출력 예 #1

본문의 예시와 같습니다.
입출력 예 #2

(0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (2, 0), (2, 1), (2, 2), (2, 3), (2, 4), (3, 0), (3, 1), (3, 2), (3, 3), (3, 4), (4, 0), (4, 1), (4, 2), (4, 3), (5, 0) 위치에 점을 찍을 수 있으며, 총 26개 입니다.
*/