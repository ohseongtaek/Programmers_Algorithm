#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;

    if (clothes.size() != 0) {
        answer++;                                           // 만약 옷이 1개라도 있다면 answer++해준다 나중에 곱을 위해 
    }
  
    for (int i = 0; i < clothes.size(); i++) {
        m[clothes[i][1]]++;                                 // map의 키가 같으면 ++
    }
    
    map<string, int>::iterator iter;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer = answer * (iter->second + 1);               // 공식
    }
    answer--;                                               // 옷을 입지 않는경우 빼야함 

    return answer;
}


int main() {
    vector<vector<string>> clo = { {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    int dab;
    dab = solution(clo);
    cout << dab << endl;
}