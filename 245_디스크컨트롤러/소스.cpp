#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());

    //들어오는것 앞을 기준으로 작은것부터 큰것으로 정렬
    //sort 정렬과는 반대의 정렬같다?
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_vector_queue;
    int index = 0;
    int end_time = 0;

    while (index < jobs.size() || !priority_vector_queue.empty()) {

        // 1. 처음 시작될때 무조건 push하게 됨 처음에 0부터 ~ 처리시간 까지 이기 때문
        //    2번으로 분기 이유는 end time 때문에

        // 3. 다음에 들어오는 값들이 추가적으로 처음 끝나는 시간보다 먼저 queue 안에 들어왔기 때문에 여기서 push
        if (index < jobs.size() && end_time >= jobs[index][0]) {
            priority_vector_queue.push(make_pair(jobs[index][1], jobs[index][0]));
            index++;
            continue;
        }

        // 2. 큐값이 비어있지 않기 때문에 들어가며
        // 처음 0의 시작일때 들어온 값에 의한 끝나는 시간을 정의하며 answer를 끝-시작 시간을 이용해 정의함

        // 4. queue 안에 들어있는 값이 정렬이 오름차순으로 되어있기 때문에 top을 이용해 기존 끝나는 시간보다 먼저 들어와서 대기하고있는 값들중 시간이 적은 것부터 계산을 하는것
        if (!priority_vector_queue.empty()) {
            end_time = end_time + priority_vector_queue.top().first;
            answer = answer + end_time - priority_vector_queue.top().second;
            priority_vector_queue.pop();
        }

        // 5. 만약 들어왔던 작업이 다 끝나고 난 후 새로운 작업이 들어왔을때
        else {
            end_time = jobs[index][0];
        }
    }


    return answer / jobs.size();
}

int main() {
    vector<vector<int>> v = { {0, 3}, {1, 9}, {2, 6} };
    cout << "solution ? " << solution(v) << endl;
    cout << endl;
}