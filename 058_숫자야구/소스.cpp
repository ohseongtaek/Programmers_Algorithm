#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 조건 : 0은 없으며 모든 자리가 겹치지 않는다.


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for (int i = 123; i <= 987; i++) {
        int B = i / 100;            //100의자리
        int S = (i / 10) % 10;      //10의자리
        int I = i % 10;             //1의자리
        
        if (B == 0 || S == 0 || I == 0) {       // 만약 하나라도 0이면 
            continue;
        }
        if (B == S || B == I || S == I) {       // 만약 같은수가 있으면 
            continue;
        }

        for (int j = 0; j < baseball.size(); j++) {     // 반복한다 위의 for문에서 숫자가 나왔을 때 입력과 마찬가지인 경우 answer++
            int Strike = 0;
            int Ball = 0;
            int baseball_temp = baseball[j][0];
            int baseball_temp_B = baseball_temp / 100;          // 입력한 수의 백의자리 
            int baseball_temp_S = (baseball_temp / 10) % 10;    // 입력한 수의 십의자리  
            int baseball_temp_I = baseball_temp % 10;           // 입력한 수의 일의자리 

            if (baseball_temp_B == 0 || baseball_temp_S == 0 || baseball_temp_I == 0) {
                break;
            }

            if (B == baseball_temp_B) Strike++;
            if (S == baseball_temp_S) Strike++;
            if (I == baseball_temp_I) Strike++;

            if (baseball[j][1] != Strike) {
                break;
            }

            if (B == baseball_temp_S || B == baseball_temp_I) Ball++;
            if (S == baseball_temp_B || S == baseball_temp_I) Ball++;
            if (I == baseball_temp_B || I == baseball_temp_S) Ball++;
            if (baseball[j][2] != Ball) {
                break;
            }
            
            if (j == baseball.size() - 1) answer++;         //  입력한 수만큼 위의 패턴을 모두 만족할때 answer ++ 이 되는것

        }

    }
    return answer;
}

int main() {
    vector<vector<int>> v = { {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1} };
    int dab;
    dab = solution(v);
    cout << dab;
}