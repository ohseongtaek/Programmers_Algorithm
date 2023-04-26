#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int finger[(const int)1e5 + 1][10][10];

const int AlreadyFinger[10][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};
int DP(int idx, int left, int right, string& number)
{
	if (idx == number.length())
	{
		return 0;
	}

	int& result = finger[idx][left][right];

	if (result != -1)
	{
		return result;
	}

	int cur = number[idx] - '0';

	if (left == cur || right == cur)
	{
		return result = 1 + DP(idx + 1, left, right, number);
	}

    result = min(DP(idx + 1, cur, right, number) + AlreadyFinger[left][cur], DP(idx + 1, left, cur, number) + AlreadyFinger[right][cur]);
	return result;}int solution(string numbers) 
{
    int answer = 0;
    memset(finger, -1, sizeof(finger));
    answer = DP(0, 4, 6, numbers);
    return answer;
}

int main()
{
    vector<string> number = { "1756", "5123" };
    vector<int> d = { 10,8 };
    
        
    for (int i = 0; i < d.size(); i++)
    {
        int ans = solution(number[i]);
        if (ans == d[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
        }
    }
}


/*
민희는 항상 왼손 엄지를 4 위에, 오른손 엄지를 6 위에 두고 타이핑을 시작합니다. 
엄지 손가락을 움직여 다음 숫자를 누르는 데에는 일정 시간이 듭니다. 민희는 어떤 두 숫자를 연속으로 입력하는 시간 비용을 몇몇 가중치로 분류하였습니다.

이동하지 않고 제자리에서 다시 누르는 것은 가중치가 1입니다.
상하좌우로 인접한 숫자로 이동하여 누르는 것은 가중치가 2입니다.
대각선으로 인접한 숫자로 이동하여 누르는 것은 가중치가 3입니다.
같지 않고 인접하지 않은 숫자를 누를 때는 위 규칙에 따라 가중치 합이 최소가 되는 경로를 따릅니다.
예를 들어 1 위에 있던 손가락을 0 으로 이동하여 누르는 것은 2 + 2 + 3 = 7 만큼의 가중치를 갖습니다.
단, 숫자 자판은 버튼의 크기가 작기 때문에 같은 숫자 버튼 위에 동시에 두 엄지 손가락을 올려놓을 수 없습니다. 
즉, 어떤 숫자를 눌러야 할 차례에 그 숫자 위에 올려져 있는 손가락이 있다면 반드시 그 손가락으로 눌러야 합니다.

숫자로 이루어진 문자열 numbers가 주어졌을 때 최소한의 시간으로 타이핑을 하는 경우의 가중치 합을 return 하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ numbers의 길이 ≤ 100,000
numbers는 아라비아 숫자로만 이루어진 문자열입니다.
입출력 예
numbers	result
"1756"	10
"5123"	8
입출력 예 설명
입출력 예 #1
왼손 엄지로 17, 오른손 엄지로 56을 누르면 가중치 10으로 최소입니다.

입출력 예 #2
오른손 엄지로 5, 왼손 엄지로 123을 누르거나 오른손 엄지로 5, 왼손 엄지로 1, 오른손 엄지로 23을 누르면 가중치 8로 최소입니다.
*/