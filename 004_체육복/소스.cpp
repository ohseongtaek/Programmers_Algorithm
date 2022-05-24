#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> list(n, 1);         // 기본 1 잃어버리면 0 2벌은 2
    int answer = 0;
    for (int i = 0; i < lost.size(); i++) {
        list[lost[i] - 1]--;        // list[1] -> 0, list[3] -> 0
    }
    for (int i = 0; i < reserve.size(); i++) {
        list[reserve[i] - 1]++;     // list[0] -> 1, list[2] -> 2, list[4] ->1      따라서 1 0 2 0 1
    }
    for (int i = 0; i < list.size(); i++) {     //list size(5)
        if (list[i] == 0) {                     //잃어버린 사람일때 (0일때) i가 1이나 3일때 
            if (i != 0 && list[i - 1] == 2) {   // 앞사람이 빌려줄수있을때 
                list[i - 1]--;
                list[i]++;
            }
            else if (i != list.size() - 1 && list[i + 1] == 2) { // 뒷사람이 빌려줄수있을때 
                list[i + 1]--;
                list[i]++;
            }
        }
    }
    for (int i = 0; i < list.size(); i++) {
        if (list[i] != 0) {     // 잃어버린 사람빼고 출력함 
            answer++;
        }
    }
    return answer;
}