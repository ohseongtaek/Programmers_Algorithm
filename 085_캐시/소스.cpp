#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> v(cacheSize);

	if (cacheSize == 0) {           //캐시사이즈 0일경우 모두 +5 로 return
		return cities.size() * 5;
	}

	for (int i = 0; i < cities.size(); i++) {

		bool flag = false;

		for (int k = 0; k < cities[i].length(); k++) {      //무조건 소문자로 변경 모든 문자열을 
			if (isupper(cities[i][k])) {
				cities[i][k] = tolower(cities[i][k]);
			}
		}

		for (int j = 0; j < v.size(); j++) {
			if (v[j] == cities[i]) {
				flag = true;
				answer++;           //success
				//cout << "i1 ? " << i << " value ? " << answer << endl;
				v.erase(remove(v.begin(), v.end(), v[j]), v.end());
				v.push_back(cities[i]);
				break;
			}
		}
		if (flag == false) {  //Not success and push
			if (v.size() >= cacheSize) {
				v.erase(remove(v.begin(), v.end(), v[0]), v.end());
				v.push_back(cities[i]);
				answer += 5;
				//cout << "i2 ? " << i << " value ? " << answer << endl;
			}
			else {
				v.push_back(cities[i]);
				answer += 5;
				//cout << "i3 ? " << i << " value ? " << answer << endl;
			}
		}

	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return answer;
}