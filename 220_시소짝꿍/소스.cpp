#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(vector<int> weights) 
{
    long long answer = 0;

    //몸무게 범위 100 ~ 1000 
    vector<long long> v(1001, 0);

    //현재 들어온 벡터의 몸무게가 있는것을 하나씩 체크해주기 
    for (int i = 0; i < weights.size(); i++)
    {
        v[weights[i]]++;
    }

    // 현재 몸무게에 2:3 3:4 2:4  에 대한 값을 모두 계산해서 넣어주기 단, 1000 이 최대이므로 1000을 넘으면 없다고 생각하고 넣지 않음 
    for (int i = 0; i < weights.size(); i++)
    {
        long long calWeights = 0;

        if (weights[i] % 2 == 0)
        {
            // 2:3 인경우 계산후 벡터에 있는 값을 넣어준다 0일수도있고 아닐수도있음 
            calWeights = (weights[i] / 2) * 3;
            if (calWeights <= 1000)
            {
                answer += v[calWeights];
            }
        }
        if (weights[i] % 3 == 0)
        {
            // 3:4 인경우 계산후 벡터에 있는 값을 넣어준다 0일수도있고 아닐수도있음 
            calWeights = (weights[i] / 3) * 4;
            if (calWeights <= 1000)
            {
                answer += v[calWeights];
            }
        }
        // 2:4 인경우 계산후 벡터에 있는 값을 넣어준다 0일수도있고 아닐수도있음 
		calWeights = weights[i] * 2;
		if (calWeights <= 1000)
		{
			answer += v[calWeights];
		}
    }

    // 100 ~ 1000몸무게까지 계산해서 같은 몸무게인경우 조합의수로 모든 경우의수를 더해준다
    for (int i = 100; i <= 1000; i++)
    {
        if (v[i] >= 2)
        {
            answer += (long long)(v[i] * (v[i] - 1)) / 2;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> v = { {100,180,360,100,270} };
    long long test = solution(v[0]);

    if (test == 4)
    {
        cout << " good " << endl;
    }
    else
    {
        cout << " error " << endl;
    }

}