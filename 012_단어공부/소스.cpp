#include<iostream>
using namespace std;

int main() {
	string str;
	int maax=0;					//최대값인듯
	int arr[26] = { 0 };		//알파벳 배열의 숫자의 세는것 
	int index;					//배열 인덱스값
	int count=0;				//최댓값 세는곳 
	cin >> str;					//문자열 입력 

	for (int i = 0; i < str.length(); i++) {			// 입력받은 문자열만큼 for문실행해서 대문자나 소문자 구분없이 a면 0에 저장하는것 
		int n = str[i];
		if (n < 97) {
			arr[n - 65]++;
		}
		else {
			arr[n - 97]++;
		}
	}

	for (int j = 0; j < 26; j++) {						// 해당 배열의 값에서 최대값을 추출함 그리고 해당 인덱스 번호도 가져옴 
		if (arr[j] > maax) {
			maax = arr[j];
			index = j;
		}
	}

	for (int k = 0; k < 26; k++) {						// 맥스값이 2개일때의 예외처리이다 count로 맥스값의 수를센다  그리고 2이상이면 ?출력후 return
		if (arr[k] == maax) {
			count++;
			if (count >= 2) {
				cout << "?" << endl;
				return 0;
			}
		}
	}
	cout << (char)(index + 65) << endl;

	return 0;
}