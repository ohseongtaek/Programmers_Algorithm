#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> babbling) 
{
	int answer = 0;
	vector<string> good = { "aya","ye","woo","ma" };
	vector<string> go = { "ayaaya","yeye","woowoo","mama" };

	for (int i = 0; i < babbling.size(); i++)
	{
		string ctx = babbling[i];

		//while (true)
		//{
			for (int i = 0; i < good.size(); i++)
			{
				string str = good[i];

				while (true)
				{
					int idx = ctx.find(str);
					if (idx == std::string::npos)
					{
						break;
					}
					else
					{
						ctx.insert(idx, "_");
						ctx.erase(idx + 1, str.size());
					}
				}
			}
		//}
			while (true)
			{
				int idx = ctx.find("_");
				if (idx == std::string::npos)
				{
					break;
				}
				else
				{
					ctx.erase(idx, 1);
				}
			}

			if (ctx == "")
			{
				bool flag = false;
				for (int j = 0; j < go.size(); j++)
				{
					if (babbling[i].find(go[j]) != std::string::npos)
					{
						flag = true;
					}
				}

				if (flag == false)
				{
					answer++;
				}
			}
	}
	return answer;
}

int main()
{
	vector<vector<string>> v = { {"myea", "aya", "yee", "u", "maa"},{"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"} };
	for (int i = 0; i < v.size(); i++)
	{
		cout << solution(v[i]) << endl;
	}
}