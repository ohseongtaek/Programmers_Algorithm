#include<iostream>
#include<algorithm>
using namespace std;
//DP[i] = DP[i - 3] + Arr[i - 1] + Arr[i] vs DP[i - 2] + Arr[i] vs DP[i - 1]
int arr[10001] = { 0 };
int result[10001] = { 0 };
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	result[0] = arr[0] = 0;		//0 은 제외하고 1부터 1잔으로 취급함 여기서 애초에 마지막잔을 마실필요가없다
	result[1] = arr[1];
	result[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		result[i] = max(result[i - 3] + arr[i - 1] + arr[i], max(result[i - 2] + arr[i], result[i - 1]));
		//위는 점화식인데 잘보면 result 3일때 부터 시작해서 3잔에서 최대값을 가지고 계속 늘린다 그리고 4잔 5잔일때를 구하는데 구할때 
		//n-3 의 최대값 + n-1 + n 으로 3잔연속일 경우를 제외한 값을 구하고
		// 다음으로는 n-2 의 값 의 최대값 + n에있는 양
		// 다음으로는 n-1 까지 최대값을 비교해 최대를 저장한다  
		//cout << result[i] << endl;
	}
	cout << result[n] << endl;


	return 0;
}