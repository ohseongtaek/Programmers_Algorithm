#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;



string solution(vector<string> survey, vector<int> choices) 
{
	string answer = "";

	map<char, int> m;

	for (int i = 0; i < survey.size(); i++)
	{
		char left = survey[i][0];
		char right = survey[i][1];
		int c = choices[i];
		
		switch (c)
		{
			case 1: m[left] += 3; break;
			case 2: m[left] += 2; break;
			case 3: m[left] += 1; break;
			case 5: m[right] += 1; break;
			case 6: m[right] += 2; break;
			case 7: m[right] += 3; break;
			default: break;
		}
	}

	answer += (m['R'] >= m['T']) ? "R" : "T";
	answer += (m['C'] >= m['F']) ? "C" : "F";
	answer += (m['J'] >= m['M']) ? "J" : "M";
	answer += (m['A'] >= m['N']) ? "A" : "N";


	return answer;
}

int main()
{
	vector<vector<string>> a = { {"AN", "CF", "MJ", "RT", "NA"}, {"TR", "RT", "TR"} };
	vector<vector<int>> b = { {5, 3, 2, 7, 5}, {7, 1, 3} };
	
	//"TCMA",	"RCJA"

	for (int i = 0; i < a.size(); i++)
	{
		cout << solution(a[i],b[i]) << endl;
	}
}

		