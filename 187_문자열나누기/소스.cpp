#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) 
{
	int answer = 0;
	
	bool start = true;
	int firstCnt = 0;
	int secondCnt = 0;
	string slice_str = "";
	vector<string> vec_slice;

	for (int i = 0; i < s.size(); i++)
	{
		// 새로운 문자열 시작할때 
		if (start == true)
		{
			slice_str += s[i];
			firstCnt++;
			start = false;
		}
		else
		{
			// 첫번째 인덱스랑 같은경우 
			if (slice_str[0] == s[i])
			{
				slice_str += s[i];
				firstCnt++;
			}
			// 첫번째 인덱스랑 다른경우 
			else
			{
				slice_str += s[i];
				secondCnt++;
			}

			if (firstCnt == secondCnt)
			{
				vec_slice.push_back(slice_str);
				slice_str = "";
				firstCnt = 0;
				secondCnt = 0;
				start = true;
			}
		}

		// 마지막 문자인경우 
		if (i == s.size() - 1)
		{
			if (slice_str != "")
			{
				vec_slice.push_back(slice_str);
			}
		}

	}

	answer = vec_slice.size();
	
	return answer;
}

int main()
{
	vector<string> test = { "baaa","banana","abracadabra","aaabbaccccabba","a"};

	for (int i = 0; i < test.size(); i++)
	{
		int dab = solution(test[i]);
		printf("answer = %d\n", dab);
	}
	
	return 0;
}

