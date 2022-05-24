#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i = 0, j = 0;
    sort(people.begin(), people.end());
    for (i = people.size() - 1; i >= j; i--) {
        if (people[i] + people[j] > limit) {
            answer++;
        }
        else {
            j++;
            answer++;
        }
    }
    return answer;
}