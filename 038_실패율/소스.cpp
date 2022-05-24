#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> a, pair<double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;		// 만약 실패율이 같으면 낮은걸로 정렬 
	}
	return a.first > b.first;		// 실패율이 다르면 실패율 높은걸로 정렬 

}


vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector <pair<double, int>> vp;

	for (int i = 1; i <= N; i++) {			//스테이지 수만큼 전체 반복 
		int totalnum = 0;
		int reach = 0;

		for (int j = 0; j < stages.size(); j++) {	//스테이지 배열의 크기만큼 벡터 
			if (stages[j] >= i) {
				totalnum++;
				if (stages[j] == i) {
					reach++;
				}
			}
		}
		if (reach == 0) {
			vp.push_back(make_pair(0, i));
			continue;
		}

		double sum = (double)reach / (double)totalnum;
		vp.push_back(make_pair(sum, i));
	}

	sort(vp.begin(), vp.end(), comp);

	for (int i = 0; i < vp.size(); i++) {
		answer.push_back(vp[i].second);
	}


	return answer;
}