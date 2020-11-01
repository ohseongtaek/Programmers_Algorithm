#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


/* 효율성 1번 실패 코드
bool diff(string a, string b){
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[a.size()-i-1]){
            return false;
        }
    }
    return true;
}

int solution(string s)
{
    int answer = 1;

    int s_len =s.size();

    // Case 1 : if s = ""
    if(s_len == 0){
        return 0;
    }

    // Case 2 : if s = "a"   -> return 1
    // Case 3 : if a = "ABA" -> return 3
    while(1){

        // Case 2 same
        if(s_len == 1){
            break;
        }
        //diff front string
        string front = "";

        //diff back string
        string back = "";

        for(int i=0; i<=s.size()-s_len; i++){

            int temp = s_len/2;


            //s_len -> 1,3,5,7 ...
            if(s_len % 2 == 1){
                front = s.substr(i,temp);
                back = s.substr(temp + i + 1, temp);
                if(diff(front,back)){
                    return s_len;
                }
            }

            //s_len -> 2,4,6,8 ...
            else{
                front = s.substr(i,temp);
                back = s.substr(temp + i, temp);
                reverse(back.begin(),back.end());
                if(diff(front,back)){
                    return s_len;
                }
            }
        }
        s_len--;
    }
    return answer;
}
*/

int solution(string s) {

    int s_len = s.size();

    // 1 보다 클때 무조건 해당 루틴
    while (s_len > 1) {

        //cout <<"s_len length ? "<< len << endl;   debug code

        // for 문에서는 만약 총 10글자 일때 0,9 || 0,8 || 0,7 이런식으로 줄여나가거나 1,9 || 2,9 || 3,9 이런식으로 늘림
        for (int i = 0; i <= s.size() - s_len; i++) {
            int left = i;
            int right = s_len - 1 + i;
            bool flag = true;

            //cout <<"i = ? " << i << "LEFT = ? " << left << "RIGHT = ? " << right << endl; debug code

            //for 문에서 정해진 범위에서 가운데로 집합하면서 다른문자열이 있는지 찾아내는 루틴
            while (left < right) {
                if (s[left] != s[right]) {
                    flag = false;
                    break;
                }
                left++;
                right--;
            }

            //가장 긴 팰리드롭을 찾는거부터 시작하기 때문에 max,min을 구분할 필요가 없음
            if (flag) {
                return s_len;
            }

        }

        s_len--;
    }
    return 1;
}

int main() {
    string s = "abaabaaaaaaa";
    int d = solution(s);
    cout << d << endl;
}