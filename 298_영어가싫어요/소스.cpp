#include <string>
#include <vector>

using namespace std;

long long solution(string numbers)
{
	long long answer = 0;
	vector<string> num = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	for (int j = 0; j < num.size(); j++)
	{
		while (true)
		{
			int idx = numbers.find(num[j]);
			if (idx != string::npos)
			{
				numbers.replace(idx, num[j].size(), to_string(j));
			}
			else
			{
				break;
			}
		}
	}

	answer = stoll(numbers);
	return answer;
}

int main()
{
	solution("onetwothreefourfivesixseveneightnine");
}