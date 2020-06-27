#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int temp[1001][1001] = { 0 };

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (int i = 1; i <= board.size(); i++) {
        for (int j = 1; j <= board[0].size(); j++) {
            int min_up_leftup_left = min(min(temp[i - 1][j], temp[i][j - 1]), temp[i - 1][j - 1]) + 1;
            int board_number = board[i - 1][j - 1];
            temp[i][j] = min_up_leftup_left * board_number;
            answer = max(answer, temp[i][j]);
        }
    }

    return pow(answer, 2);
}