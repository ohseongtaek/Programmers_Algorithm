#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) 
{
	int answer = 0;
	string str = "";
	
	for (int i = 0; i < ingredient.size(); i++)
	{
		str += to_string(ingredient[i]);
		int len = str.size();
		if (len >= 4)
		{
			int idx = len - 4;
			string tmp = str.substr(idx);
			if (tmp == "1231")
			{
				str = str.substr(0, idx);
				answer++;
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> a = {{ 2, 1, 1, 2, 3, 1, 2, 3, 1 }, { 1, 3, 2, 1, 2, 1, 3, 1, 2 }};

	for (int i = 0; i < a.size(); i++)
	{
		cout << solution(a[i]) << endl;
	}
}