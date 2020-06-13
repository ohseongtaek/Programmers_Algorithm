#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	int n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	int k = gcd(n, m);
	int l = n * m / k;
	answer.push_back(k);
	answer.push_back(l);
	return answer;
}