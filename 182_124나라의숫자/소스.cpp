#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    string str[3] = { "4","1","2" };

    deque<string> s;                        //13 -> 111

    while (n != 0) {
        if (n % 3 == 1) {
            s.push_front(str[n % 3]);
            n = n / 3;

        }
        else if (n % 3 == 2) {
            s.push_front(str[n % 3]);
            n = n / 3;
        }
        else if (n % 3 == 0) {
            s.push_front(str[n % 3]);
            n = n / 3;
            n--;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        answer = answer + s[i];
    }


    return answer;
}