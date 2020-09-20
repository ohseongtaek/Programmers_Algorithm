#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MIN 9999
using namespace std;
vector<string> temp_time;
vector<string> name;
vector<string> music;
vector<int> Real_time;


typedef struct ALL {
public:
    int index = 0;
    string tempname;
    string tempmusic;
    int temptime = 0;
}ALL;

// 각각의 정보 추출
void str_out(vector<string> temp) {
    for (unsigned i = 0; i < temp.size(); i++) {
        int count = 0;
        int j_second_count = 0;
        int j_first_count = 0;

        for (unsigned j = 0; j < temp[i].size(); j++) {
            j_second_count++;

            if (temp[i][j] == ',') {
                count++;
                string str = temp[i].substr(j_first_count, j_second_count - 1);
                if (count == 1 || count == 2) {
                    temp_time.push_back(str);
                }
                else if (count == 3) {
                    name.push_back(str);
                }
                j_first_count += j_second_count;
                j_second_count = 0;

                if (count == 3) {
                    string tt = temp[i].substr(j_first_count, temp[i].size());
                    music.push_back(tt);
                }
            }
        }
    }
}

// 문자열 치환 #있는것은 앞에꺼 소문자로
string str_XY(string temp) {
    for (unsigned i = 0; i < temp.size(); i++) {
        //C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
        if (temp[i] == '#') {
            if (temp[i - 1] == 'E') {
                continue;
            }
            temp[i - 1] += 32;
            temp.erase(i, 1);
        }
        else {
            continue;
        }
    }
    return temp;
}

// time 문자열을 숫자로 변환 후 그 차이계산
void music_length(vector<string> v) {
    //time 문자열 숫자로 변환
    vector<int> temp_sum;
    for (unsigned i = 0; i < v.size(); i++) {
        string temp = "";
        int sum = 0;
        for (unsigned j = 0; j < v[i].size(); j++) {
            if (j == 2) {
                continue;
            }
            else {
                temp += v[i][j];
            }

        }
        // 숫자의 차이 구하기
        for (unsigned k = 0; k < temp.length(); k++) {
            if (k == 0) {
                sum += (temp[k] - '0') * 36000;
            }
            else if (k == 1) {
                sum += (temp[k] - '0') * 3600;
            }
            else if (k == 2) {
                sum += (temp[k] - '0') * 600;
            }
            else if (k == 3) {
                sum += (temp[k] - '0') * 60;
            }
        }
        // 숫자 임시 저장소
        temp_sum.push_back(sum);

        // 만약 2개 들어왔으면 두개의 차이 계산
        if (temp_sum.size() % 2 == 0) {
            Real_time.push_back((temp_sum[1] - temp_sum[0]) / 60);
            temp_sum.clear();
        }
    }
}

// 시간만큼 문자열 늘리거나 줄이는 함수
vector<string> str_add(vector<int> t, vector<string> m) {
    for (unsigned i = 0; i < t.size(); i++) {
        int count = t[i] - m[i].size();
        if (count > 0) {
            for (int j = 0; j < count; j++) {
                m[i] += m[i][j];
            }
        }
        else {
            if (count == 0) {
                continue;
            }
            else if (count < 0) {
                int x = m[i].size() - (count * -1);
                m[i].erase(x, (count * -1));
            }
        }
    }
    return m;
}
// a ba
string DAB(string n, vector<string> m) {
    vector<int> dab;
    string a = "(None)";
    vector<ALL> all_information;

    for (unsigned i = 0; i < m.size(); i++) {
        bool next = false;
        int k = m[i].size();
        for (int j = 0; j < k; j++) {

            if (n[0] == m[i][0]) {
                bool update = true;
                for (unsigned k = 0; k < n.size(); k++) {
                    if (n[k] != m[i][k]) {
                        update = false;
                    }
                }
                // 조건에 맞는것만 구조체에 push
                if (update) {
                    ALL all_info;
                    all_info.index = i;
                    all_info.tempmusic = music[i];
                    all_info.tempname = name[i];
                    all_info.temptime = Real_time[i];
                    //cout << "temptime ? " << all_info.temptime << endl;
                    all_information.push_back(all_info);
                    next = true;

                    dab.push_back(i);
                }
                m[i].erase(0, 1);
            }
            else {
                m[i].erase(0, 1);
            }
            if (next) {
                break;
            }
        }

    }
    /*
        for (int i = 0; i < all_information.size(); i++) {
            cout << all_information[i].index << endl;
            cout << all_information[i].tempmusic << endl;
            cout << all_information[i].tempname << endl;
            cout << all_information[i].temptime << endl;
            cout << endl;
        }
    */

    if (all_information.size() > 1) {
        int time_max = 0;
        unsigned index_min = MIN;
        int idx = 0;
        int music_count = 0;

        //최대 음악시간을 찾는 for문
        for (unsigned i = 0; i < all_information.size(); i++) {
            time_max = max(time_max, all_information[i].temptime);
        }

        //cout << "time_max -> " << time_max <<endl;

        //최대 음악시간이 여러개일 때 몇개있는지 찾는 for문 및 1개일때는 바로 해당 이름 리턴
        for (unsigned i = 0; i < all_information.size(); i++) {
            if (time_max == all_information[i].temptime) {
                music_count++;
                idx = i;
                index_min = min(index_min, i);
            }
        }

        //cout << "music_count ? " << music_count <<endl;

        //조건 일치 + 재생시간 도 일치 = 먼저입력된 음악 제목 반환하는 조건
        if (music_count > 1) {
            return all_information[index_min].tempname;
        }
        //조건 일치 최대 재생시간이 1개 따라서 바로 이름 반환
        else {
            return all_information[idx].tempname;
        }

    }
    else if (all_information.size() == 1) {
        //cout << "1" << endl;
        return all_information[0].tempname;
    }
    else {
        //cout << "0" << endl;
        return a;
    }

}



string solution(string m, vector<string> musicinfos) {
    string answer = "";

    //1 각 정보를 추출하는 함수 // Clear
    str_out(musicinfos);

    //2 치환하는 함수  // Clear
    m = str_XY(m);
    for (unsigned i = 0; i < music.size(); i++) {
        music[i] = str_XY(music[i]);
        //cout <<"??? " << music[i] << endl;
    }

    //3 time 벡터에 시간 차이만큼 가지고있다 // Clear
    music_length(temp_time);

    //4 숫자만큼 문자열 늘리거나 줄이는 함수 // Clear
    music = str_add(Real_time, music);


    //debug code
    for (unsigned i = 0; i < music.size(); i++) {
        cout << music[i] << endl;
    }


    //5 입력받은 문자열을 가지고 실제 음악과 비교해 같은것에 대한 name을 리턴하는 함수
    answer = DAB(m, music);

    return answer;
}


int main() {
    string m = "ABC";
    vector<string> str = { "13:00,13:05,ONE,D#ABC","12:00,12:06,TWO,ABCD","09:00,09:06,THREE,ABC" };
    cout << solution(m, str) << endl;
}