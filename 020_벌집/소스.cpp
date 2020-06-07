#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count=1;				//출력할것 처음부터1이니 1로 초기화 
	int next=1;					//다음칸으로 가기위한 변수 
	int temp=1;					//일시적으로 저장하는 변수 

	while (1) {
		if (next >= n) {		//만약 입력값보다 다음칸으로 가기위한 수의 크기보다 작다? ex입력값이 12인데 다음입력값은 3번째 껍질 부터인것임 그럼 나가는것 
			break;
		}
		temp = (count++) * 6;	//수를 하나씩 늘린다 당연히 벌집의 칸이 6의배수이기때문에 6씩 곱한다.
		next = next + temp;		//일시적인 저장변수에 현재 수의범위를 더하면 다음칸의 범위가나옴 
	}
	cout << count << endl;

	return 0;
}