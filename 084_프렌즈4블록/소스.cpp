#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool update = false;

	while (update == false) {
		vector<vector<bool>> temp(m, vector<bool>(n));
		update = true;

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] == 0) {
					continue;
				}
				if ((board[i][j] == board[i][j + 1]) &&		//오른쪽 
					(board[i][j] == board[i + 1][j]) &&		//아래
					(board[i][j] == board[i + 1][j + 1])) {	//대각선 
					temp[i][j] = 1;
					temp[i][j + 1] = 1;
					temp[i + 1][j] = 1;
					temp[i + 1][j + 1] = 1;
					update = false;
				}
			}
		}

		for (int i = 0; i < m; i++) {	// 내리기 원래 있던 값은 0으로 초기화 
			for (int j = 0; j < n; j++) {
				if (temp[i][j] == 1) {
					answer++;
					for (int k = i - 1; k >= 0; k--) {
						board[k + 1][j] = board[k][j];
						board[k][j] = 0;
					}
				}
			}
		}

	}
	return answer;
}