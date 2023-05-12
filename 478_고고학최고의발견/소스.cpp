#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

void rotate(std::vector<std::vector<int>>& copyArr, int row, int col, int cnt, int N)
{
    copyArr[row][col] = (copyArr[row][col] + cnt) % 4;
    if (row > 0)
    {
        copyArr[row - 1][col] = (copyArr[row - 1][col] + cnt) % 4;
    }
    if (col > 0) 
    {
        copyArr[row][col - 1] = (copyArr[row][col - 1] + cnt) % 4;
    }
    if (row < N - 1) 
    {
        copyArr[row + 1][col] = (copyArr[row + 1][col] + cnt) % 4;
    }
    if (col < N - 1) 
    {
        copyArr[row][col + 1] = (copyArr[row][col + 1] + cnt) % 4;
    }
}

int solution(const std::vector<std::vector<int>> clockHands) 
{
    const int N = clockHands.size();
    int answer = INT_MAX;

    std::vector<std::vector<int>> copyArr(N, std::vector<int>(N));

    for (int i = 0; i < std::pow(4, N); i++) 
    {
        copyArr = clockHands;
        int count = 0;
        int a = i;
        for (int j = 0; j < N; j++) 
        {
            int cnt = std::floor(a % 4);
            a /= 4;
            rotate(copyArr, 0, j, cnt, N);
            count += cnt;
        }

        for (int row = 1; row < N; row++) 
        {
            for (int col = 0; col < N; col++) 
            {
                int cnt = (4 - copyArr[row - 1][col]) % 4;
                rotate(copyArr, row, col, cnt, N);
                count += cnt;
            }
        }

        bool allZero = true;
        for (const auto& val : copyArr[N - 1]) 
        {
            if (val != 0) 
            {
                allZero = false;
                break;
            }
        }

        if (allZero) 
        {
            answer = std::min(answer, count);
        }
    }

    return answer;
}

int main()
{
	solution({ {0, 3, 3, 0}, {3, 2, 2, 3}, {0, 3, 2, 0}, {0, 3, 3, 3} });
}
