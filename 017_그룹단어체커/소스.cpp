#include<iostream>
#include<string>
using namespace std;
int cnt = 0;
void check(string a);
int main()
{
	int n;				//전체 반복횟수 입력 
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;				//문자열 입력 
		check(str);				//함수 호출 
	}
	cout << cnt;
	return 0;
}

void check(string a)
{
	int siz = a.size();					//입력받은 문자열 ex happy와 twenteen
	for (int i = 0; i < siz - 2; i++)	// 입력받은 문자의 첫번째는 happy이므로총 3번 반복됨 
	{
		if (a[i] != a[i + 1])			// h와 a가 같지 않으면 들어감 (첫번째와 두번째 비교) 
		{
			for (int j = i + 2; j < siz; j++) //이후 첫번째와 3번째부터 끈까지 비교함 
				if (a[j] == a[i])				//만약 같은게 있으면 리턴 
					return;
		}

	}
	cnt++;
}