#include <string>
#include <vector>
#include <iostream>
using namespace std;

string Convert(int i, int n) {
    string H[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    int temp;
    string Convert_Return = "";
    while (i / n != 0) {                          //진법변환
        temp = i % n;
        Convert_Return = H[temp] + Convert_Return;
        i = i / n;
    }

    Convert_Return = H[i % n] + Convert_Return;   //마지막 수 포함하는 코드

    return Convert_Return;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    int total_number = t * m;                    //이 변수는 만약 미리구할숫자의 수가 3이고 참가인원이 4명이면 총 12자리까지 숫자를 구해놓아야한다
    string temp = "";
    
    for (int i = 0; i < total_number; i++) {
        temp += Convert(i, n);                   //n진법으로 i를 교환 한다 미리구할숫자를 n진법으로 교환 및 s 문자열에 저장
        //cout << temp << endl;
    }


    int p_temp = p - 1;                          // 순서가 첫번째라면 0부터 말을해야해서 -1하기

    for (int i = 0; i < t; i++) {
        answer += temp[p_temp];                  // 배열 이덱스에 대해 순서에 따라 answer에 합치기
        p_temp += m;                             // 참가인원 plus
    }

    return answer;
}

int main() {
    int n = 16;  // 진법
    int t = 4;  // 미리구할숫자의 수
    int m = 10;  // 참가인원
    int p = 1;  // 튜브순서

    cout << solution(n, t, m, p) << endl;
}