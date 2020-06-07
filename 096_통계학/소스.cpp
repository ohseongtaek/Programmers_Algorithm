#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int main() {

	vector<int> v;
	int test;
	int k;
	int sum = 0;
	cin >> test;			//입력할 수의 갯수 5개입력 등등
	if (test % 2 != 1) {
		return -1;
	}

	//입력할 수의 갯수만큼 입력한 수가 들어감 
	for (int i = 0; i < test; i++) {
		cin >> k;
		v.push_back(k);
	}

	//벡터안에 정수들 정렬 
	sort(v.begin(), v.end());

	//평균값계산 후 반올림 round로 
	double one = 0;
	for (int i = 0; i < v.size(); i++) {
		one = one + v[i];
	}
	double one_result;
	one_result = one / test;
	cout << round(one_result) << endl;
	//end

	//가운데 값 출력 
	int ind = 0;
	ind = v.size() / 2;
	cout << v[ind] << endl;
	//end

	//가장많이 나타나는값 출력 똑같으면 2번째로 작은 값 출력	 pair<값(숫자),키(빈도수)>
	vector<pair<int, int> > st;
	vector<int>::size_type i;

	for (i = 0; i < v.size(); i++) {
		if (st.empty()) {
			st.push_back(pair<int, int>(v[i], 1));
			continue;
		}

		if (st.back().first == v[i]) {
			pair<int, int> tmp = st.back();
			tmp.second++;
			st.pop_back();
			st.push_back(tmp);
		}
		else {
			st.push_back(pair<int, int>(v[i], 1));
		}
	}

	if (st.size() > 1) {
		sort(st.begin(), st.end(), comp);

		if (st[0].second == st[1].second) {
			cout << st[1].first << endl;
		}
		else {
			cout << st[0].first << endl;
		}
	}
	else {
		cout << st[0].first << endl;
	}

	//end

	//최대 최소 차이값 
	int ca, ac;
	ca = v.front();
	ac = v.back();
	cout << v.back() - v.front();
	//end

	return 0;
}