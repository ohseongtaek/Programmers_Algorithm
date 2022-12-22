#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int solution(int k, int m, vector<int> score) 
{
	int answer = 0;
	int box = 0;
	int mini = 10;
	sort(score.begin(), score.end(), cmp);

	for (int i = 0; i < score.size(); i++)
	{
		mini = min(mini, score[i]);
		box++;
		
		if (box == m)
		{
			box = 0;
			answer += m * mini;
			mini = 10;
		}
	}

	return answer;
}

int main()
{
	vector<int> k = { 3,4 };
	vector<int> m = { 4,3 };
	vector<vector<int>> v = { {1, 2, 3, 1, 2, 3, 1} ,{4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2} };
	
	for (int i = 0; i < k.size(); i++)
	{
		cout << solution(k[i], m[i], v[i]) << endl;
	}

	//8,33
}