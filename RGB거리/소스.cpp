#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][3] = { 0, };
int cost[1001][3] = { 0, };
int main()
{
	int iInput = 0;

	cin >> iInput;
	for (int i = 1; i <= iInput; ++i)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	for (int i = 1; i <= iInput; ++i)
	{
		d[i][0] = cost[i][0] + min(d[i - 1][1], d[i - 1][2]);
		d[i][1] = cost[i][1] + min(d[i - 1][0], d[i - 1][2]);
		d[i][2] = cost[i][2] + min(d[i - 1][0], d[i - 1][1]);
	}

	cout << min(d[iInput][0], min(d[iInput][1], d[iInput][2])) << endl;

	return 0;

}