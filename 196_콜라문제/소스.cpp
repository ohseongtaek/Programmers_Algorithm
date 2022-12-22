#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
	int answer = 0;

	while (1) 
	{
		if (n < a)
		{
			break;
		}
		answer += ((n / a)*b);
		n = (n / a)*b + n % a;
	}

	return answer;
}

int main()
{
	vector<int> a = { 2,3 };
	vector<int> b = { 1,1 };
	vector<int> n = { 20,20 };
		//19,		9

	for (int i = 0; i < a.size(); i++)
	{
		cout << solution(a[i], b[i], n[i]) << endl;
	}
}