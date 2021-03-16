#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <queue>
#include <map>
using namespace std;


// Using the two pointer Algorithm

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> gems_box;

    // 초기화
    for (int i = 0; i < gems.size(); i++) {
        gems_box[gems[i]] = 0;
    }

    int gems_box_total = gems_box.size();
    int start_point = 0;
    int end_point = 0;
    int gems_end = gems.size();
    int gems_count = 0;

    answer.push_back(0);
    answer.push_back(gems_end);
    while (1) {
        // 만약 보석함이 최종 보석함과 갯수가 같다면 다 들어온 상태이다 이때 start_point 를 +1 해주기 위해서 해당 보석 카운트를 - 해주고 보석함에서도 - 로 빼준다.
        if (gems_count >= gems_box_total) {
            if (gems_box[gems[start_point]] - 1 == 0) {
                gems_count--;
            }
            gems_box[gems[start_point++]]--;
        }

        // end_point 가 끝에 도착하면 탈출
        else if (end_point == gems_end) {
            break;
        }

        // gems의 보석이 중복제거한 보석함에 들어있지 않으면 새로 들어온 보석이므로 보석카운트를 + 해주고 해당 보석함 map 도 + 그리고 end 또한 + 해준다.
        else {
            if (gems_box[gems[end_point]] == 0) {
                gems_count++;
            }
            gems_box[gems[end_point]]++;
            end_point++;
        }

        // 거리를 계산하기 위한 조건문!
        if (gems_count == gems_box_total) {
            if (end_point - start_point < answer[1] - answer[0]) {
                answer[0] = start_point;
                answer[1] = end_point;
            }
        }
    }
    answer[0]++;
    return answer;
}
int main() {
    vector<string> g = { "A", "B", "C", "C", "D", "A","B","C","D" };
    vector<int> d;
    d = solution(g);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << endl;
    }

    return 0;
}