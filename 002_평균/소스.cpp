#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	double arr[1000] = { 0 };
	double sum=0;
	double maax = 0 ;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int k = 0; k < n; k++) {
		maax = max(maax, arr[k]);		//알고리즘 헤더에 의한 배열의 최댓값 구하는 함수max를 사용한것 
	}

	//cout << maax;

	for (int j = 0; j < n; j++) {
		arr[j] = arr[j] / maax * 100;
	}
	
	for (int x = 0; x < n; x++) {
		sum = sum + arr[x];
	}

	cout << sum / n << endl;


	return 0;
}