#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int index;
	cin >> str;
	for (char i = 'a'; i <= 'z'; i++) {		// 아스키코드를 올려서 문자열을 생성하는데 해당 문자열에 
		index = str.find(i);				// index를 이용해서 해당 인덱스를 리턴한다 str에서 find 찾아서 해당 index를 리턴하는데 string은 배열형식으로 되어있어서
		cout << index << " ";				// 같은 문자열을 찾으면 index에 해당 배열인덱스를 리턴한다 만약 못찾으면 -1을 리턴한다 
	}
	return 0;
}