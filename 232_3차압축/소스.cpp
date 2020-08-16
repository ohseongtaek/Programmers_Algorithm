#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    string temp = "";
    int index;
        // A~Z push (A,1 .. Z,26)
    for (index = 1; index < 27; index++) {
        temp += 'A' + index - 1;
        m.emplace(temp, index);
        temp = "";
    }
    for (int i = 0; i < msg.size(); i++) {
        string temp = "";
        temp += msg[i];
        //cout << temp << endl;
        int j = i;
        int count = 0;

        // 기본값에 없는 문자열이 나올때까지 뒤에꺼 추가 
        while (m.find(temp) != m.end()) {
            count++;
            j++;
            temp += msg[j]; 
        }

        i += count - 1;
        m.emplace(temp, index++);
        temp.pop_back();
        answer.emplace_back(m[temp]);
    }

    return answer;
}


int main() {
	string msg = "KAKAO";
	vector<int> a;
	a = solution(msg);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}

}