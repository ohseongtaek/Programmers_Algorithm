#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 참조 사이트 : https://prgms.tistory.com/108 (월간 코드 챌린지 해설 사이트)


//열 번호가 감소하는 방향으로 dx칸 이동하는 쿼리(query(0, dx))
//열 번호가 증가하는 방향으로 dx칸 이동하는 쿼리(query(1, dx))
//행 번호가 감소하는 방향으로 dx칸 이동하는 쿼리(query(2, dx))
//행 번호가 증가하는 방향으로 dx칸 이동하는 쿼리(query(3, dx))

enum DIRECTION
{
    COL_DOWN = 0,   // 열 번호가 감소
    COL_UP,         // 열 번호가 증가
    ROW_DOWN,       // 행 번호가 감소
    ROW_UP          // 행 번호가 증가
};


long long solution(int n, int m, int x, int y, vector<vector<int>> queries) 
{
    long long answer = -1;

    // 값 초기화 (행과 열을 따로 분리해서 본다)
    long long pos_Arr[4] = { x,x,y,y };

    // 역순 쿼리 시작 
    for (int i = queries.size() - 1; i >= 0; i--)
    {
        // 열번호 감소 
        if (queries[i][0] == COL_DOWN)
        {
            if (pos_Arr[2] > 0)
            {
                if (queries[i][1] > m - 1 - pos_Arr[2])
                {
                    return 0;
                }
                if (pos_Arr[2] + queries[i][1] >= m)
                {
                    pos_Arr[2] = m - 1;
                }
                else
                {
                    pos_Arr[2] = pos_Arr[2] + queries[i][1];
                }
            }
            if (pos_Arr[3] + queries[i][1] >= m)
            {
                pos_Arr[3] = m - 1;
            }
            else
            {
                pos_Arr[3] = pos_Arr[3] + queries[i][1];
            }
        }
        // 열번호 증가 
        else if (queries[i][0] == COL_UP)
        {
            if (pos_Arr[3] < m - 1)
            {
                if (queries[i][1] > pos_Arr[3])
                {
                    return 0;
                }
                if (pos_Arr[3] - queries[i][1] < 0)
                {
                    pos_Arr[3] = 0;
                }
                else
                {
                    pos_Arr[3] = pos_Arr[3] - queries[i][1];
                }
            }
            if (pos_Arr[2] - queries[i][1] < 0)
            {
                pos_Arr[2] = 0;
            }
            else
            {
                pos_Arr[2] = pos_Arr[2] - queries[i][1];
            }
        }
        // 행번호 감소
        else if (queries[i][0] == ROW_DOWN)
        {
            if (pos_Arr[0] > 0)
            {
                if (queries[i][1] > n - 1 - pos_Arr[0])
                {
                    return 0;
                }
                if (pos_Arr[0] + queries[i][1] >= n)
                {
                    pos_Arr[0] = n - 1;
                }
                else
                {
                    pos_Arr[0] = pos_Arr[0] + queries[i][1];
                }
            }
            if (pos_Arr[1] + queries[i][1] >= n)
            {
                pos_Arr[1] = n - 1;
            }
            else
            {
                pos_Arr[1] = pos_Arr[1] + queries[i][1];
            }
        }
        // 행번호 증가 
        else if (queries[i][0] == ROW_UP)
        {
            if (pos_Arr[1] < n - 1)
            {
                if (queries[i][1] > pos_Arr[1])
                {
                    return 0;
                }
                if (pos_Arr[1] - queries[i][1] < 0)
                {
                    pos_Arr[1] = 0;
                }
                else
                {
                    pos_Arr[1] = pos_Arr[1] - queries[i][1];
                }
            }
            if (pos_Arr[0] - queries[i][1] < 0)
            {
                pos_Arr[0] = 0;
            }
            else
            {
                pos_Arr[0] = pos_Arr[0] - queries[i][1];
            }
        }
    }

    answer = (pos_Arr[1] - pos_Arr[0] + 1) * (pos_Arr[3] - pos_Arr[2] + 1);
    return answer;
}

int main()
{
    vector<int> n = { 2,2 };
    vector<int> m = { 2,5 };
    vector<int> x = { 0,0, };
    vector<int> y = { 0,1 };

    vector<vector<vector<int>>> q = { {{2, 1}, {0, 1}, {1, 1}, {0, 1}, {2, 1}}, { {3, 1}, {2, 2}, {1, 1}, {2, 3}, {0, 1}, {2, 1}} };
    
    vector<int> answer = { 4,2 };

    for (int i = 0; i < q.size(); i++)
    {
        long long test = solution(n[i], m[i], x[i], y[i], q[i]);
        if (test == answer[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error [result] = " << test << ", [want] = " << answer[i] << endl;
        }
    }
        
    
}