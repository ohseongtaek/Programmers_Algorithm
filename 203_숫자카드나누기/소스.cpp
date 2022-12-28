#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetLarge(vector<int> pos, vector<int> impos)
{
	int maxNum = 0;
	vector<int> vec;

	// 첫번째 수에서 나누어 떨어지는 수들 모두 찾기 
	for (int i = 2; i <= pos[0]; i++)
	{
		if (pos[0] % i == 0)
		{
			bool flag = false;
			bool flag2 = false;
			for (int j = 0; j < pos.size(); j++)
			{
				if (pos[j] % i != 0)
				{
					flag = true;
					break;
				}
			}

			if (flag == false)
			{
				for (int j = 0; j < impos.size(); j++)
				{
					if (impos[j] % i == 0)
					{
						flag2 = true;
						break;
					}
				}
				if (flag2 == false)
				{
					maxNum = max(maxNum, i);
				}
			}
		}
	}

	return maxNum;
}

int solution(vector<int> arrayA, vector<int> arrayB) 
{
	int answer = 0;
	int A = 0;
	int B = 0;

	sort(arrayA.begin(), arrayA.end());
	sort(arrayB.begin(), arrayB.end());

	A = GetLarge(arrayA, arrayB);
	B = GetLarge(arrayB, arrayA);

	return (A > B) ? A : B;
}

int main()
{
	vector<vector<int>> a = { {10,17}, {10,20}, {14,35,119} };
	vector<vector<int>> b = { {5,20}, {5,17}, {18,30,102} };
	vector<int> result = { 0, 10, 7 };

	for (int i = 0; i < result.size(); i++)
	{
		int k = solution(a[i],b[i]);
		if (k == result[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error = " << k << ", wnat = " << result[i] << endl;
		}
	}
}
/*
철수와 영희는 선생님으로부터 숫자가 하나씩 적힌 카드들을 절반씩 나눠서 가진 후, 
다음 두 조건 중 하나를 만족하는 가장 큰 양의 정수 a의 값을 구하려고 합니다.

철수가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고 
영희가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a

영희가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고, 
철수가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a

카드들에 10, 5, 20, 17이 적혀 있는 경우에 대해 생각해 봅시다. 
만약, 철수가 [10, 17]이 적힌 카드를 갖고, 영희가 [5, 20]이 적힌 카드를 갖는다면 
두 조건 중 하나를 만족하는 양의 정수 a는 존재하지 않습니다. 

하지만, 철수가 [10, 20]이 적힌 카드를 갖고, 
영희가 [5, 17]이 적힌 카드를 갖는다면, 
철수가 가진 카드들의 숫자는 모두 10으로 나눌 수 있고, 
영희가 가진 카드들의 숫자는 모두 10으로 나눌 수 없습니다. 
따라서 철수와 영희는 각각 [10, 20]이 적힌 카드, [5, 17]이 적힌 카드로 나눠 가졌다면 조건에 해당하는 양의 정수 a는 10이 됩니다.

철수가 가진 카드에 적힌 숫자들은 모두 3으로 나눌 수 없고, 
영희가 가진 카드에 적힌 숫자는 모두 3으로 나눌 수 있습니다. 따라서 3은 조건에 해당하는 양의 정수입니다. 하지만, 철수가 가진 카드들에 적힌 숫자들은 모두 7로 나눌 수 있고, 영희가 가진 카드들에 적힌 숫자는 모두 7로 나눌 수 없습니다. 따라서 최대값인 7을 return 합니다.
*/