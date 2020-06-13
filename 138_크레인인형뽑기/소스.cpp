#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> s;
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int board_size = board.size();

	for (int i = 0; i < moves.size(); i++) {
		int result = moves[i] - 1;

		for (int j = 0; j < board_size; j++) {
			if (board[j][result] != 0) {
				if (!s.empty() && s.top() == board[j][result]) {
					s.pop();
					answer = answer + 2;

				}
				else {
					s.push(board[j][result]);
				}
				board[j][result] = 0;
				break;
			}
		}
	}

	return answer;
}