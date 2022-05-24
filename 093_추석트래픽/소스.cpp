#include <string>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#define endl '\n'
using namespace std;


//시간 문자열을 모두 ms 단위로 변경 function
int time_To_MS(string time) {

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));
    int ms = stoi(time.substr(9, 3));

    minute += hour * 60;
    second += minute * 60;
    ms += second * 1000;

    return ms;
}


int doing_To_MS(string doing) {
    //입력형식이 0.2s 이런식임 따라서 s지워줘야함
    doing.erase(doing.end() - 1);

    //float to ms control
    float end_ms_temp = stof(doing);
    int end_ms = end_ms_temp * 1000;
    return end_ms;
}


int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start;
    vector<int> end;

    for (int i = 0; i < lines.size(); i++) {
        //공백을 기준으로 문자열 분리
        //time 과 doing 변수만 사용하면 됨
        stringstream ss(lines[i]);
        string trash_date, time, doing;
        ss >> trash_date >> time >> doing;

        int end_time = time_To_MS(time);

        //처음과 끝을 포함하므로 +1 해주기
        int start_time = end_time - doing_To_MS(doing) + 1;

        start.push_back(start_time);
        end.push_back(end_time);
    }

    // debug code
    for (int i = 0; i < start.size(); i++) {
        cout << start[i] << endl;
        cout << end[i] << endl;
        cout << "================" << endl;
    }

    //최대 count 를 설정할 변수
    int max_temp_count = 0;

    //끝나는 시간을 기준으로 1초간 처리되는 양을 count 하는 for문
    for (int i = 0; i < end.size(); i++) {
        int count = 1;
        //끝나는 시간을 기준으로 1초기 때문에 +1000 하기
        int end_time_cal = end[i] + 1000;
        for (int j = i + 1; j < start.size(); j++) {
            if (start[j] < end_time_cal) {
                count++;
            }
        }
        max_temp_count = max(count, max_temp_count);
    }

    answer = max_temp_count;

    return answer;
}

int main() {
    vector<string> v = { "2016-09-15 20:59:57.421 0.351s",
                       "2016-09-15 20:59:58.233 1.181s",
                       "2016-09-15 20:59:58.299 0.8s",
                       "2016-09-15 20:59:58.688 1.041s",
                       "2016-09-15 20:59:59.591 1.412s",
                       "2016-09-15 21:00:00.464 1.466s",
                       "2016-09-15 21:00:00.741 1.581s",
                       "2016-09-15 21:00:00.748 2.31s",
                       "2016-09-15 21:00:00.966 0.381s",
                       "2016-09-15 21:00:02.066 2.62s" };
    cout << "solution ? " << solution(v) << endl;
    cout << endl;
}