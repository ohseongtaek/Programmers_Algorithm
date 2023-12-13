#include <string>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int getAllCnt(int h, int m, int s)
{
	int rtn = -1;
	double dbth = 0;
	double dbtm = 0;
	double dbts = 0;

	dbth = fmod(h * 30 + m * 0.5 + s * 0.5 / 60, 360);
	dbtm = fmod(m * 6 + s * 0.1, 360);
	dbts = s * 6;

	if (dbts >= dbtm)
	{
		rtn += 1;
	}
	if (dbts >= dbth)
	{
		rtn += 1;
	}

	rtn = rtn + (h * 60 + m) * 2 - h;

	if (h >= 12)
	{
		rtn -= 2;
	}
	return rtn;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) 
{
	int startTime = 0;
	int endTime = 0;
    int answer = -1;

	startTime = getAllCnt(h1, m1, s1);
	endTime = getAllCnt(h2, m2, s2);

	answer = endTime - startTime;

	if ((h1 == 0 || h1 == 12) && m1 == 0 && s1 == 0)
	{
		answer += 1;
	}
	
  return answer;
}

int main()
{
	vector<vector<int>> v = { {0,5,30,0,7,0 },
							  {12,0,0,12,0,30},
							  {0,6,1,0,6,6},
							  {11,59,30,12,0,0},
							  {11,58,59,11,59,0},
							  {1,5,5,1,5,6},
							  {0,0,0,23,59,59} };

	vector<int> r = { 2,1,0,1,1,2,2852 };

	for (int i = 0; i < v.size(); i++)
	{
		int result = solution(v[i][0], v[i][1], v[i][2], v[i][3], v[i][4], v[i][5]);
		if (result == r[i])
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error " << endl;
		}
	}


}