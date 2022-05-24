#include <vector>

using namespace std;

int ost(int location, int s, int g, int x, int y, vector<vector<int>>& ALL) {

	int G_sum = 1;
	if (x < 0 || y < 0 || x >= s || y >= g || location != ALL[x][y]) {
		return 0;
	}
	else {
		ALL[x][y] = 0;		// 리턴받은거 숫자세고 0으로 초기화 
		G_sum = G_sum + ost(location, s, g, x - 1, y, ALL); // 위	(0,X 일때 범위벗어남,, 예외처리)
		G_sum = G_sum + ost(location, s, g, x + 1, y, ALL); // 아래 (5,X 일때 범위 벗어남,, 예외처리)
		G_sum = G_sum + ost(location, s, g, x, y - 1, ALL); // 왼쪽 (X,0 일때 범위 벗어남,, 예외처리)
		G_sum = G_sum + ost(location, s, g, x, y + 1, ALL); // 오른쪽 (X,3일때 범위 벗어남,, 예외처리)
	}
	return G_sum;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	int sum = 0;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0) {
				continue;
			}
			else {
				sum = ost(picture[i][j], m, n, i, j, picture);
				number_of_area++;
				if (sum > max_size_of_one_area) {
					max_size_of_one_area = sum;
				}
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}