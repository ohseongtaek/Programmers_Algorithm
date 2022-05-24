

//시간 초과 코드 

/*
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<int> first_vec;

	for (int i = 0; i < edge.size(); i++) {
		if (edge[i][0] == 1) {
			first_vec.push_back(edge[i][1]);
			edge.erase(edge.begin() + i);
			i--;
		}
		else if (edge[i][1] == 1) {
			first_vec.push_back(edge[i][0]);
			edge.erase(edge.begin() + i);
			i--;
		}
		else {
			continue;
		}
	}

	vector<int> final_count;

	while (true) {
		for (int i = 0; i < first_vec.size(); i++) {
			for (int j = 0; j < edge.size(); j++) {
				if (first_vec[i] == edge[j][0]) {
					final_count.push_back(edge[j][1]);
					edge.erase(edge.begin() + j);
					j--;
				}
				else if (first_vec[i] == edge[j][1]) {
					final_count.push_back(edge[j][0]);
					edge.erase(edge.begin() + j);
					j--;
				}
				else {
					continue;
				}

			}
		}

		for (int i = 0; i < final_count.size(); i++) {
			for (int j = 0; j < first_vec.size(); j++) {
				if (final_count[i] == first_vec[j]) {
					final_count.erase(final_count.begin() + i);
				}
			}
			//cout << "final " << final_count[i] << endl;
		}
		if (edge.empty()) {
			final_count.erase(unique(final_count.begin(), final_count.end()), final_count.end());
			answer = final_count.size();
			break;
		}
		else {
			final_count.clear();
		}
	}
	return answer;
}

int main() {
	int n = 6;
	vector<vector<int>> v = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}, {6,7} };
	cout << "solution ? " << solution(n, v) << endl;
	cout << endl;
}
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<int>> v2(n + 1);
	vector<int> distance(n + 1, -1);
	queue<int> q;
	distance[1] = 0;

	// 그래프 생성 ( in-out )
	for (int i = 0; i < edge.size(); i++)
	{
		v2[edge[i][0]].push_back(edge[i][1]);
		v2[edge[i][1]].push_back(edge[i][0]);
	}

#ifdef _DEBUG
	for (int i = 0; i < v2.size(); i++)
	{
		for (int j = 0; j < v2[i].size(); j++)
		{
			cout << "i,j = " <<  i << " , " << j << "   " << v2[i][j] << " ";
		}
		cout << endl;
	}
#endif

	// BFS 실행 Queue 동작 
	q.push(1);

	while (q.empty() == false)
	{
		int current_node = q.front();
		q.pop();

		for (int i = 0; i < v2[current_node].size(); i++)
		{
			int k = v2[current_node][i];
			if (distance[k] == -1)
			{
				distance[k] = distance[current_node] + 1;
				q.push(k);
			}
		}
	}

#ifdef _DEBUG
	cout << " ----- " << endl;
	for (int i = 0; i < distance.size(); i++)
	{
		cout << distance[i] << endl;
	}
#endif

	int nMax = 0;
	for (int i = 0; i < distance.size(); i++)
	{
		nMax = max(distance[i], nMax);
	}

	for (int i = 0; i < distance.size(); i++)
	{
		if (distance[i] == nMax)
		{
			answer++;
		}
	}


	return answer;
}

int main()
{
	int n = 6;
	vector<vector<int>> edge = { { 3,6 }, { 4,3 }, { 3,2 }, { 1,3 }, { 1,2 }, { 2,4 }, { 5,2 } };
	int dab = solution(n, edge);
	cout << dab << endl;
}