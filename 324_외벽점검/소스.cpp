#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// min 값을 찾는것이라 8이 최대값이므로 9로 설정 
int answer = 9;

// dist 최대수 = 8
bool Choice[8];

// 순서대로 담을 벡터 
vector<int> V;

bool Cmp(int A, int B)
{
    if (A > B)
    {
        return true;
    }
    return false;
}

vector<int> Next_Vector(vector<int> w_temp, int start, int n)
{
    for (int j = 1; j < w_temp.size(); j++)
    {
        w_temp[j - 1] = w_temp[j];
    }
    w_temp[w_temp.size() - 1] = start + n;

    return w_temp;
}

void Need_person(vector<int> Weak, vector<int> Dist, int N)
{
    // 외벽 어느 부분을 시작점으로 해야하는지 정확하지 않기때문에 for문으로 반복하기 
    for (int i = 0; i < Weak.size(); i++)
    {
        int idx = 0;
        int Cnt;
        bool Flag = false;

        for (int j = 0; 
            // j는 사람수로 전체 순열보다 작고
            // answer 는 기존의 최솟값보다 하나 더 크게 들어온다면 계산 자체가 필요없어서 예외 
            // flag 가 false 인 경우는 현재 벡터의 인원들로 외벽점검을 마친경우에는 큰 for문을 돌면서 시작점을 재설정한다.
            (j < V.size()) && (j + 1 < answer) && (Flag == false); 
            j++)
        {
            int End = Weak[idx] + Dist[V[j]];
            while (End >= Weak[idx])
            {
                idx++;
                if (idx == Weak.size())
                {
                    Cnt = j + 1;
                    Flag = true;
                    break;
                }
            }
        }
        if (Flag == true)
        {
            answer = min(answer, Cnt);
        }
     
        int Start = Weak[0];
        Weak = Next_Vector(Weak, Start, N);
    }
}

void ALL_CASE(int Cnt, vector<int> Weak, vector<int> Dist, int N)
{
    if (Cnt == Dist.size())
    {
        // 인원이 다 채워졌을경우에도 특정인원만 필요하는 경우가 생길수있음 무조건 따라서 해당 값을 체크하기 위해 함수처리 
        Need_person(Weak, Dist, N);
        return;
    }

    for (int i = 0; i < Dist.size(); i++)
    {
        // 선택된 사람이라면 계속 
        if (Choice[i] == true)
        {
            continue;
        }
        // 아니라면 무조건 선택 
        Choice[i] = true;
        // 선택된 사람 벡터에 추가 
        V.push_back(i);
        // 재귀로 추가 하기 
        ALL_CASE(Cnt + 1, Weak, Dist, N);
        V.pop_back();
        Choice[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    // 이동할수있는 거리에 대해 내림차순으로 정렬    
    sort(dist.begin(), dist.end(), Cmp);

    // 한 사람이 처리할수 있는지 전체 벡터 반복
    vector<int> w_temp = weak;
    for (int i = 0; i < w_temp.size(); i++)
    {
        int start = w_temp[0];
        int end = w_temp[w_temp.size() - 1];
        // 시작 점과 마지막 점의 차이가 가장 거리를 많이 이동할수있는 사람 1명인 경우에 리턴 1
        if (end - start <= dist[0])
        {
            return 1;
        }

        // 아닌경우 배열을 하나씩 밀어줌 ex) 1,2,3 -> 2,3,1
        w_temp = Next_Vector(w_temp,start,n);
    }

    // dist 즉 사람을 어느순서로 투입시키느냐에 따라 결과가 달라짐 순열로 구현 
    ALL_CASE(0, weak, dist, n);

    if (answer == 9)
    {
        return -1;
    }
    return answer;
}

int main()
{
    int n = 12;
    vector<vector<int>> weak = { {1,5,6,10},{1,3,4,9,10} };
    vector<vector<int>> dist = { {1,2,3,4},{3,5,7} };

    for (int i = 0; i < weak.size(); i++)
    {
        cout << i << " = " << solution(n, weak[i], dist[i]) << endl;
    }
}