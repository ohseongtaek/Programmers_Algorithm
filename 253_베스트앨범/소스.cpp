#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool comp2(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first > b.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<bool> visit(genres.size(), false);
    vector<pair<string, int>> vp;
    vector<pair<int, int>> answer_temp;

    for (int i = 0; i < genres.size(); i++) {
        string str = genres[i];
        int plays_sum = 0;
        for (int j = 0; j < genres.size(); j++) {
            if (visit[j] == false && str == genres[j]) {
                visit[j] = true;
                plays_sum += plays[j];
            }
        }
        if (plays_sum != 0) {
            vp.push_back(make_pair(str, plays_sum));
        }
    }

    sort(vp.begin(), vp.end(), comp);

    /* Test Code
    for(int i=0; i<vp.size(); i++){
        cout << vp[i].first << "  " << vp[i].second << endl;
    }
    */

    for (int i = 0; i < vp.size(); i++) {
        string str = vp[i].first;
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == str) {
                answer_temp.push_back(make_pair(plays[j], j));
            }
        }

        sort(answer_temp.begin(), answer_temp.end(), comp2);

        if (answer_temp.size() == 1) {
            answer.push_back(answer_temp[0].second);
        }
        else if (answer_temp.size() >= 2) {
            answer.push_back(answer_temp[0].second);
            answer.push_back(answer_temp[1].second);
        }

        answer_temp.clear();

    }

    /* Test Code
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << endl;
    }
    */

    return answer;
}

int main() {
    vector<int> dab;
    vector<string> g = { "classic", "pop", "classic", "classic", "pop" };         // -> 4130 pop -> classic
    vector<int> p = { 500, 600, 150, 800, 2500 };

    dab = solution(g, p);

    for (int i = 0; i < dab.size(); i++) {
        cout << dab[i] << endl;
    }
}