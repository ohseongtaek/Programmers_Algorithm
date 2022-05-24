#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<char> first = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };    // 캐릭터 이름들 
int dist_temp[26];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    do {
        for (int i = 0; i < first.size(); i++) {
            dist_temp[first[i] - 'A'] = i;              // 거리 구하기 위한 배열 생성 및 값 넣어줌 
        }
        bool Switch_Case_Temp = true;

        for (int j = 0; j < data.size(); j++) {
            int first_number = data[j][0] - 'A';
            int second_number = data[j][2] - 'A';

            int Distance = abs(dist_temp[first_number] - dist_temp[second_number]) - 1;     // 거리를 구하는 것 A와 C사이에 수를 구하는 것이기 때문에 -1을해줌 안해주면 A와 C사이의 거리가 2가 나옴 C를 포함해서 

            char Sic = data[j][3];
            int result = data[j][4] - '0';
            switch (Sic) {                      // 문제에 수식은 단 3개 = < > 만 나옴 
            case '=': 
                if (Distance != result) {
                    Switch_Case_Temp = false;
                }
                break;

            case '>' :
                if (Distance <= result) {
                    Switch_Case_Temp = false;
                }
                break;

            case '<' :
                if (Distance >= result) {
                    Switch_Case_Temp = false;
                }
                break;

            default:
                cout << "Not UserCase" << '\n';
            }

            if (!Switch_Case_Temp) {           // 첫번째 조건에서 이미 실패한것이면 바로 break 로 탈출
                break;
            }

        }
        if (Switch_Case_Temp) {
            answer++;
        }
    } while (next_permutation(first.begin(), first.end()));     // 배열의 수식 경우의수로 나열하는 템플릿 

    return answer;
}

int main() {
    int dab;
    int n = 2;
    vector<string> dat = { "N~F=0", "R~T>2" };
                          //012 3 4 
    dab = solution(n, dat);

    cout << dab;

    return 0;
}
