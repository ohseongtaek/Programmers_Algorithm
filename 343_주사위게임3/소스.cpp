#include <string>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
	int answer = 0;
	map<int, int> m;
	map<int, int>::iterator iter;

	vector<pair<int, int>> vp;

	int temp = a;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			temp = a;
		if (i == 1)
			temp = b;
		if (i == 2)
			temp = c;
		if (i == 3)
			temp = d;

		m[temp]++;
	}

	if (m.size() == 1)
	{
		answer = 1111 * a;
	}
	else if (m.size() == 2)
	{
		bool flag = false;
		vector<int> v;
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->second);
		}
		iter = m.begin();
		if (iter->second == 2)
		{
			int left = 0;
			int right = 0;
			for (iter = m.begin(); iter != m.end(); iter++)
			{
				if (left == 0)
				{
					left = iter->first;
				}
				else
				{
					right = iter->first;
				}
			}
			answer = (left + right) * abs(left - right);
		}
		else
		{
			int left = 0;
			int right = 0;
			for (iter = m.begin(); iter != m.end(); iter++)
			{
				if (iter->second == 3)
				{
					left = iter->first;
				}
				else
				{
					right = iter->first;
				}
			}
			answer = pow(10 * left + right, 2);
		}

	}
	else if (m.size() == 3)
	{
		int left = 0;
		int r1 = 0;
		int r2 = 0;
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->second == 1 && r1 == 0)
			{
				r1 = iter->first;
			}
			else if(iter->second == 1 && r2==0)
			{
				r2 = iter->first;
			}
		}
		answer = r1 * r2;
	}
	else if (m.size() == 4)
	{
		int mm = 7;
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			mm = min(mm, iter->first);
		}
		answer = mm;
	}



	return answer;
}

int main()
{
	solution(2, 5, 2, 6);
}