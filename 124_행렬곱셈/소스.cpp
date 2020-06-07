#include<iostream>
using namespace std;

int arr[101][101];
int arr1[101][101];
int result[101][101];
int main() {
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				result[i][j] = result[i][j] + (arr[i][k] * arr1[k][j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}