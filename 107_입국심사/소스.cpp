#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//이분법 이용 및 자료형 주의 문제
long long solution(int n, vector<int> times) {
    long long answer;

    sort(times.begin(), times.end());

    long long min = 1;
    long long max = n * (long long)times[times.size() - 1];
    long long avg = (min + max) / 2;
    answer = max;


    //정상적인 상황에서는 계속 루프
    while (min <= max) {
        long long temp_ncount = 0;
        avg = (min + max) / 2;

        //평균시간동안 처리할 수 있는 사람의 수 확인
        for (int i = 0; i < times.size(); i++) {
            temp_ncount += avg / times[i];
        }

        //만약 처리를 더 많이 하거나 같다면 max값을 줄임
        if (temp_ncount >= n) {
            //answer는 일단 저장한다 최소값을 리턴해야하기 때문에
            answer = avg;
            max = avg - 1;
        }
        //만약 처리를 더 적게 한다면 min값을 올림
        else {
            min = avg + 1;
        }
    }
    return answer;
}

int main() {
    int n = 6;
    vector<int> t = { 7,10 };
    cout << solution(n, t) << endl;
}