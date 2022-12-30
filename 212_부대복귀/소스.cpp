#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> line[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
	vector<int> answer;

	for (int i = 0; i < roads.size(); i++)
	{
		line[roads[i][0]].push_back(roads[i][1]);
		line[roads[i][1]].push_back(roads[i][0]);
	}

	for (int i = 0; i < sources.size(); i++)
	{
		int curr;
		int next;

		vector<int> visit(n + 1, -1);
		queue<int> q;
		
		visit[sources[i]] = 0;
		
		q.push(sources[i]);

		while (!q.empty() && visit[destination] == -1)
		{
			curr = q.front();
			q.pop();

			for (int j = 0; j < line[curr].size(); j++)
			{
				next = line[curr][j];
				if (visit[next] > -1)
				{
					continue;
				}

				q.push(next);
				visit[next] = visit[curr] + 1;
			}
		}
		
		answer.push_back(visit[destination]);
	}
	
	return answer;
}

int main()
{
	vector<int> n = { 3,5 };
	vector<vector<vector<int>>> v = { {{1, 2}, {2, 3}} ,{{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}} };
	vector<vector<int>> s = { {2,3},{1,3,5} };
	vector<int> d = { 1, 5 };

	vector<vector<int>> r = { { 1,2 } , {2,-1,0} };

	for (int i = 0; i < r.size(); i++)
	{
		vector<int> dab = solution(n[i], v[i], s[i], d[i]);
		bool flag = false;
		for (int j = 0; j < dab.size(); j++)
		{
			if (dab[j] != r[i][j])
			{
				flag = true;
			}
		}

		if (flag == true)
		{
			cout << " error " << endl;
		}
		else
		{
			cout << " good " << endl;
		}
	}

}
