#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 스타수열이란 ? 
// => x(부분수열)의 길이가 2이상
// => 각 부분수열의 교집합의 원소가 1개 이상이다 => ex) {0,1} {0,3} => 0이 부분수열의 교집합!
// => 각 부분수열의 값이 같으면 안됨 => ex) {1,1} => 부분수열의 값이 같음!


int solution(vector<int> a) 
{
    int answer = -1;
    
    // 특정 숫자가 등장하는 횟수를 카운트하기 위한 벡터 
    vector<int> NumberCnt(a.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)
    {
        NumberCnt[a[i]]++;
    }

    // 기준이 되는 스타수열의 배열을 for문으로 반복 !
    for (int i = 0; i < NumberCnt.size(); i++)
    {
        // 파라미터에 들어오는 벡터에 등장하지 않는 숫자인 경우 
        if (NumberCnt[i] == 0)
        {
            continue;
        }
        // 숫자의 갯수가 스타수열을 만드는데 가장 많이 사용된 횟수 보다 작은 경우에는 계산 자체를 할 필요가 없음!
        // ex ) 1을 이용해 1,2 1,3 1,4 을 만들고 2를 선택했을때 2가 총 2번밖에 안나온 경우에는 탐색을 할 필요가 없음!
        if (NumberCnt[i] <= answer)
        {
            continue;
        }

        int res = 0;

        for (int j = 0; j < a.size() - 1; j++)
        {
            // 기준으로 잡은 i 의 값이 현재 인덱스와 다음인덱스에 없는 경우에는 스타수열이 될 수 없기 때문에 continue;
            if (a[j] != i && a[j + 1] != i)
            {
                continue;
            }
            // 기준으로 잡은 i 의 값이 다음 인덱스와 동일한 경우에 문제에서 제시된 기준에 충족하지 못하므로  continue;
            if (a[j] == a[j + 1])
            {
                continue;
            }

            // 위의 2가지가 아닌경우 스타수열의 갯수를 늘리고 인덱스를 2개씩 탐색하기 때문에 j++ 을 해준다.
            res++;
            j++;
        }

        answer = max(answer, res);
    }

    // 스타수열의 길이는 2배기 때문에 !
    return answer * 2;
}

int main() {

    vector<vector<int>> v = { {0} , {5, 2, 3, 3, 5, 3} ,{ 0,3,3,0,7,2,0,2,2,0 } };
    vector<int> dab = { 0,4,8 };


    for (int i = 0; i < v.size(); i++)
    {
        int a = solution(v[i]);
        if (dab[i] == a)
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << a << ", want = " << dab[i] << endl;
        }
    }

}