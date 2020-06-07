#include<iostream>
#include<string>
using namespace std;
/*
0이 짝수여야하며
옆에있는 배열이 떨어지면 안된다 ex)0101 이런경우는 안됨 0이 붙어있어야함 0010 이것도 안됨 

두번째로는 점화식을 살펴보면 arr[n] = arr[n-1] + arr[n-2] 이다 
*/
int arr[1000000+1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % 15746;
	}
	//for (int i = 0; i <= n; i++) {
	//	cout << "what?" << arr[i] << endl;
	//}
	
	cout << arr[n] << endl;

	return 0;
}