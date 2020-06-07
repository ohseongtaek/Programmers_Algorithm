#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int kg[101] = { 0 };
int value[101] = { 0 };
int d[101][100001] = { 0 };
int main() {
	int device, All_kg;
	cin >> device >> All_kg;				// 전체 물품 과 전체 무게 
	for (int i = 1; i <= device; i++) {
		cin >> kg[i];						// 물품에 따른 무게 
		cin >> value[i];					// 물품에 따른 가치 
	}

    for (int i = 1; i <= device; i++) {     // 물품 수만큼 반복한다 
        for (int j = 0; j <= All_kg; j++) { // j는 각
            d[i][j] = d[i - 1][j];
            if (j - kg[i] >= 0) {
                d[i][j] = max(d[i][j], d[i - 1][j - kg[i]] + value[i]);
            }
        }
    }

    cout << d[device][All_kg] << endl;



	return 0;
}

