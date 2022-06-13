#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 중간시간을 기준으로 작업 가능한 코어의 갯수를 리턴함 
int Work(int time_mid, vector<int> cores)
{
    // 시간이 0인경우 모든 코어가 작업이 가능하다.
    if (time_mid == 0)
    {
        return cores.size();
    }
    else
    {
        int Cnt = cores.size();

        // 중간 시간동안 각 코어가 처리할수 있는 작업량을 합산함
        for (int i = 0; i < cores.size(); i++)
        {
            Cnt += time_mid / cores[i];
        }
        return Cnt;
    }
}

int solution(int n, vector<int> cores) 
{
    int answer = 0;
    
    // 파라메트릭 서치 (이분탐색)

    int time_min = 0;
    int time_max = cores[0] * n;
    int time_item = 0;
    int time_work = 0;

    while (time_min <= time_max)
    {
        int time_mid = (time_min + time_max) / 2;
        int count = Work(time_mid, cores);

        // 작업한 량이 n 보다 크면 갱신로직
        if (count >= n)
        {
            time_max = time_mid - 1;
            time_item = time_mid;
            time_work = count;
        }
        else
        {
            time_min = time_mid + 1;
        }
    }

	// 처리한 작업량과 n의 차이 갱신
	time_work -= n;

	for (int i = cores.size() - 1; i >= 0; i--)
	{
		// 시간에 작업을 처리하는 core 
		if (time_item % cores[i] == 0)
		{
			if (time_work == 0)
			{
				answer = i + 1;
				break;
			}
			time_work--;
		}
	}
    
    return answer;
}


int main()
{
    int n = 6;
    vector<int> c = { 1,2,3 };

    int dab = solution(n, c);

    if (dab == 2)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }
}