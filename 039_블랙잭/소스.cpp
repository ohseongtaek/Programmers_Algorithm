#include <iostream>
#define MAX 100
using namespace std;

int main() {
    int num, target, goal=0, sum = 0;
    int min = 9999999;
    int arr[MAX] = { 0, };              // 배열 100으로 초기화     
    cin >> num >> target;               // 숫자의 개수와 최대 숫자 입력 
    for (int i = 0; i < num; i++)       // 숫자의 개수를 각각 입력 받음 
        cin >> arr[i];

    for (int i = 0; i < num - 2; i++)           // 만약 5개의 숫자를 입력하면 0~3까지입력받고 
        for (int j = i + 1; j < num - 1; j++)   // 1~4까지 돌고 
            for (int k = j + 1; k < num; k++)   // 2~5까지 돌고 
            {
                sum = arr[i] + arr[j] + arr[k]; // 순서 : 012 013 014 023 024 034 123 124 134 234 5C2라고 보면된다 중복되지 않게 5개의 수중에 3개뽑기 
                if (target - sum < min && target - sum >= 0) {  // 만약 최댓값에서 sum값을 뺀게 min보다 작고 (true) 최댓값에서 sum을 뺀게 0보다 크다? true
                    min = target - sum;             // 최대값에서 sum값을 밴것을 min값에 넣는다 
                    goal = sum;                     // 근접값 대입 
                }
            }
    cout << goal;
}