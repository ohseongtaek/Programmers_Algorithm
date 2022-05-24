#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    int str_size = s.size();

    int answer = str_size;

    for (int i = 1; i <= (str_size / 2); i++) {
        string result;
        string Diff_temp = s.substr(0, i);
        int count = 1;                      // 기본적으로 문자 1개는 무조건 1이기때문에 초기화

        for (int j = i; j <= str_size; j = j + i) { //범위가 < 면 마지막에 count 해놓은것 추가를 하지못함 <= 이거해야함 
            if (Diff_temp == s.substr(j, i)) {
                count++;
            }
            else {
                if (count == 1) {
                    result = result + Diff_temp;
                }
                else {
                    result = result + to_string(count) + Diff_temp;
                }
                Diff_temp = s.substr(j, i);
                count = 1;
            }
        }

        result = result + s.substr((str_size / i) * i);     // 문자열 9개이고 2개씩 자르면 1개가 안들어가기 때문에 그것을 들어가게함 
        answer = min(answer, (int)result.length());
    }
    return answer;
}