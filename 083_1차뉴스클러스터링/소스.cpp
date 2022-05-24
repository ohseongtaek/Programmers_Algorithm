#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <ctype.h>
using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;

    double U_hap = 0, N_gyo = 0;

    map<string, int> m;


    //////////////////////////////
    /////모든 문자 소문자로 변환/////
    //////////////////////////////
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + 32;
        }
        else {
            continue;
        }
    }
    for (int i = 0; i < str2.size(); i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] = str2[i] + 32;
        }
        else {
            continue;
        }
    }

    ///////////////////////////////////
    /////모든 문자 2개씩 자르기 영어만/////
    ///////////////////////////////////
    for (int i = 1; i < str1.size(); i++) {
        if (isalpha(str1[i - 1]) != 0 && isalpha(str1[i]) != 0) {
            string temp = "";
            temp += str1[i - 1];
            temp += str1[i];
            U_hap++;

            if (m.count(temp)) {  //문자를 map 함수에 넣은 후 갯수 ++
                m[temp]++;
            }
            else {               //처음 나온 문자는 무조건 1로 set
                m[temp] = 1;
            }

        }
    }


    for (int i = 1; i < str2.size(); i++) {
        if (isalpha(str2[i - 1]) != 0 && isalpha(str2[i]) != 0) {
            string temp = "";
            temp += str2[i - 1];
            temp += str2[i];

            if (m.count(temp)) {      // 교집합 ++
                if (m[temp] > 0) {    // 다중집합 예외처리
                    m[temp]--;
                    N_gyo++;
                }
                else {
                    U_hap++;
                }
            }
            else {
                U_hap++;
            }
        }
    }

    ////////////////////////////////////
    ///////////////값 리턴///////////////
    ////////////////////////////////////

    if (U_hap != 0) {
        answer = ((double)answer * (N_gyo / U_hap));
    }

    return answer;
}