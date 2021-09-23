#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
	int idx;
	int weight;
	double WinCount;
	int WinBigger;
}INFO;

bool diff(INFO a, INFO b)
{
	if (a.WinCount > b.WinCount)
	{
		return true;
	}

	if (a.WinCount == b.WinCount)
	{
		if (a.WinBigger > b.WinBigger)
		{
			return true;
		}

		if (a.WinBigger == b.WinBigger)
		{
			if (a.weight > b.weight)
			{
				return true;
			}

			if (a.weight == b.weight && a.idx < b.idx)
			{
				return true;
			}
		}
	}
	return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
	vector<int> answer;
	vector<INFO> vecinfo;

	for (int i = 0; i < head2head.size(); i++)
	{
		double wins = 0;
		double total = 0;
		int win_bigger = 0;

		for (int j = 0; j < head2head[i].size(); j++)
		{
			if (head2head[i][j] == 'N')
			{
				continue;
			}

			total++;

			if (head2head[i][j] == 'W')
			{
				wins++;
				if (weights[i] < weights[j])
				{
					win_bigger++;
				}
			}
		}

		vecinfo.push_back({ i + 1,weights[i],total ? wins / total : 0,win_bigger });
	}

	sort(vecinfo.begin(), vecinfo.end(), diff);

	for (INFO finfo : vecinfo)
	{
		answer.push_back(finfo.idx);
	}

	return answer;
}

//아래 코드는 버리는 코드 접근이 잘못됐다고 느낌 

/* 

bool Diff(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

vector<pair<int,int>> GetPercent(vector<int> weights, vector<string> head2head)
{
	vector<pair<int,int>> index_percent;

	for (int j = 0; j < head2head.size(); j++)
	{
		int win_count = 0;
		int big_weights = 0;
		int index = 0;
		for (int k = 0; k < head2head[j].size(); k++)
		{
			if (head2head[j][k] == 'W')
			{
				win_count++;
				if (weights[j] < weights[index])
				{
					big_weights++;
				}
			}
			index++;
		}
		index_percent.push_back(make_pair(win_count,big_weights));
	}

	return index_percent;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;

    vector<pair<int,int>> PerCent = GetPercent(weights,head2head);
	vector<pair<int, int>> matching = PerCent;
	sort(PerCent.begin(), PerCent.end(), Diff);

	for (int i = 0; i < matching.size(); i++)
	{
		cout << "matching = " << i  << "   "  << matching[i].first << " " << matching[i].second << endl;
		cout << "PerCent = " << i << "   " << PerCent[i].first << " " << PerCent[i].second << endl;
	}

	int index = 0;
	while (1)
	{
		if (answer.size() == PerCent.size())
		{
			break;
		}

		for (int i = 0; i < PerCent.size(); i++)
		{
			if (matching[i].first == PerCent[index].first &&
				matching[i].second == PerCent[index].second)
			{
				bool bTrue = false;
				for (int j = 0; j < answer.size(); j++)
				{
					if (answer[j] == i + 1)
					{
						bTrue = true;
						break;
					}
				}
				if (bTrue == true)
				{
					continue;
				}
				else
				{
					answer.push_back(i + 1);
					break;
				}
			}
		}
		index++;
	}
	//for (int i = 0; i < PerCent.size(); i++)
	//{
	//	int index = i+1;
	//	for (int j = 0; j < matching.size(); j++)
	//	{
	//		if (matching[j].first == PerCent[i].first &&
	//			matching[j].second == PerCent[i].second)
	//		{
	//			answer.push_back(index);
	//		}
	//	}
	//}
    return answer;
}
*/

int main()
{
    vector<int> w = { 60,70,60 };
    vector<string> h2h = { "NNN","NNN","NNN" };
    vector<int> r = solution(w, h2h);
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
}