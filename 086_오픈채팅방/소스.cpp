#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> uid_name;
    vector<string> id;
    stringstream ss;
    string token;
    string uid;
    string name;

    for (int i = 0; i < record.size(); i++) {
        ss.str(record[i]);
        ss >> token;                                        //공백으로 문자열 분리

        if (token == "Enter") {
            ss >> uid;
            id.push_back(uid);
            ss >> name;
            uid_name[uid] = name;
            answer.push_back("님이 들어왔습니다.");
        }
        else if (token == "Leave") {
            ss >> uid;
            id.push_back(uid);
            answer.push_back("님이 나갔습니다.");
        }
        else if (token == "Change") {                       //무조건 바뀐걸로 하기 때문에 map 에 넣어준다 
            ss >> uid;
            ss >> name;
            uid_name[uid] = name;
        }
        ss.clear();
    }

    /* debug code
    for (int i = 0; i < id.size(); i++) {
        cout << uid_name[id[i]]<< endl;
    }
    */

    for (int i = 0; i < answer.size(); i++) {
        answer[i] = uid_name[id[i]] + answer[i];
    }

    return answer;
}


int main() {
    vector<string> v;
    vector<string> d = { "Enter uid1234 Muzi",
                         "Enter uid4567 Prodo",
                         "Leave uid1234",
                         "Enter uid1234 Prodo",
                         "Change uid4567 Ryan" };
    v = solution(d);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

/*
["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
*/