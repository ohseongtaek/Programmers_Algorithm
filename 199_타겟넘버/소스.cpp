#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer = 0;
void search(vector<int> numbers, int target, int hap, int index_number) {
    if (index_number == numbers.size()) {
        if (hap == target) {
            answer++;
        }
        return;
    }
    search(numbers, target, hap - numbers[index_number], index_number + 1);     // first -
    search(numbers, target, hap + numbers[index_number], index_number + 1);     // first +
}

int solution(vector<int> numbers, int target) {
    search(numbers, target, 0, 0);      // search dfs -> 0 -> -1,+1 -> -1= -2,0 Consider all cases
    return answer;
}

int main() {
    int t = 3;
    vector<int> num = { 1,1,1,1,1 };
    int dab = solution(num, t);
    cout << dab;
}