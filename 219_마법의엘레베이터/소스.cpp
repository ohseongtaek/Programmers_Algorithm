#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey)
{
    int answer = 0;

    // 처음숫자에서 다음 숫자를 보고 6부터는 첫째자리 한개 더 더하구 빼는 방식으로 하는게 좋음 모든 자릿수에서 (5까지는 정상루틴이 맞음)
    while(storey)
    {
        if (storey % 10 == 5)
        {
            int temp = storey / 10;
            if (temp % 10 >= 5)
            {
                answer += 5;
                storey += 5;
            }
            else
            {
                answer += 5;
            }
        }
        else if (storey % 10 > 5)
        {
            answer += 10 - (storey % 10);
            storey += 10;
        }
        else if (storey % 10 < 5)
        {
            answer += storey % 10;
        }

        storey /= 10;
    }

    return answer;
}

int main()
{
    vector<int> st = { 75, 2554,5, 75, 555, 155 };
    vector<int> an = { 8,  16,  5, 8,  14, 11 };

    for (int i = 0; i < st.size(); i++)
    {
        int r = solution(st[i]);
        if (r == an[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    return 0;
}