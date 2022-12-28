#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> elements) 
{
	int answer = 0;
	vector<int> vec = elements;
	vector<int> vecValue;

	for (int i = 0; i < vec.size() - 1; i++)
	{
		elements.push_back(elements[i]);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i; j < vec.size() + i; j++)
		{
			int value = 0;
			for (int k = i; k <= j; k++)
			{
				value += elements[k];
			}
			vecValue.push_back(value);
		}
	}

	sort(vecValue.begin(), vecValue.end());
	vecValue.erase(unique(vecValue.begin(), vecValue.end()), vecValue.end());

	return vecValue.size();
}

int main()
{
	vector<int> a = { 7, 9, 1, 1, 4 };
	int dab = 18;

	for (int i = 0; i < a.size(); i++)
	{
		int k = solution(a);
		if (k == dab)
		{
			cout << " good " << endl;
		}
		else
		{
			cout << " error = " << k << ", wnat = " << dab << endl;
		}
	}
}