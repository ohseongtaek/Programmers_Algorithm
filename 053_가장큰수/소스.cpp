#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vs;

    for (int i = 0; i < numbers.size(); i++) {
        vs.push_back(to_string(numbers[i]));
    }

    sort(vs.begin(), vs.end(), cmp);

    /* debug code
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i] << endl;
    }
    */

    for (int i = 0; i < vs.size(); i++) {
        answer += vs[i];
    }


    // 0 0 0 -> false why? -> 0 0 0 -> return 0 if(answer[0]=0) -> all zero '0' 
    if (answer[0] == '0') {
        return "0";
    }




    return answer;
}