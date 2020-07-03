#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
/*
int convert_two(int temp_n) {
    int result = 0;
    for (int i = 1; temp_n > 0; i *= 10) {
        int binary = temp_n % 2;
        result = result + binary * i;
        temp_n = temp_n / 2;
    }
    return result;
}

int loop_one(string temp_n_str) {
    int one_temp = 0;
    for (int i = 0; i < temp_n_str.size(); i++) {
        if (temp_n_str[i] == '1') {
            one_temp++;
        }
    }
    return one_temp;
}

int convert_binary(int temp_d_int) {
    int result = 0;
    int gop = 1;
    while (temp_d_int > 0)
    {
        if (temp_d_int % 2) {
            result = result + gop;
        }
        gop = gop * 2;
        temp_d_int = temp_d_int / 10;
    }
    return result;
}
*/

// 위에는 의식의 흐름대로 코드 및 시간초과 및 오류 코드....
// 아래는 필요없는것 줄인 코드..

int Count_One_number(int temp_n) {
    int temp = 0;
    while (temp_n != 1) {
        if (temp_n % 2 == 1) {
            temp++;
        }
        temp_n = temp_n / 2;
    }
    return temp + 1;                // 맨마지막 계산이 안들어가 1을 더해주는것 
}

int solution(int n) {
    int answer = 0;
    
    int n_one_number;

    n_one_number = Count_One_number(n);
    //cout << n_one_number << endl;             debug

    while (1) {
        n++;
        if (n_one_number == Count_One_number(n)) {
            answer = n;
            break;
        }
    }
    return answer;
}

int main() {
    int num = 15;
    int dab;

    dab = solution(num);

    cout << dab;
}