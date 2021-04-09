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


bool comp(int a, int b) {
    return a > b;
}

//// 반대로 내림차순 정렬 이후에 벡터에서 차감하는 방식이 아닌
//// 그대로 B 벡터와 비교하는 방식을 이용했다.
int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    // 내림차순 정렬
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);

    // A벡터의 가장 작은 값이 B벡터의 가장 큰값보다 크거나 같다면 이는 0 을 의미한다 따라서 0 리턴
    if (A[A.size() - 1] >= B[0]) {
        return answer;
    }

    // B벡터의 인덱스를 나타내는 변수
    int B_idx = 0;

    // A벡터를 순회하면서 가장 큰 값과 B벡터의 가장 큰 값을 비교하면서 크다면 answer++ , B벡터의 인덱스를 늘려준다
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < B[B_idx]) {
            answer++;
            B_idx++;
        }
    }

    return answer;
}

//// TestCase 는 모두 통과 but 모두 시간초과가 났다
//// 하기 알고리즘은 모두 오름차순으로 정렬후에 A벡터의 가장 작은 크기를 B 벡터의 처음부터 비교해 큰것이 있으면 answer++을 하는 구조이며
//// A벡터에 가장 큰 크기의 숫자가 있는경우에는 해당 원소만 빼주는 알고리즘이다.

/*
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    bool all_biger = true;

    for(int i=0; i<A.size(); i++){
        int diff_a = A[i];

        for(int j=0; j<B.size(); j++){
            if(diff_a < B[j]){
                answer++;
                A.erase(A.begin()+i);
                i--;
                B.erase(B.begin()+j);
                all_biger = false;
                break;
            }
            else{
                continue;
            }
        }
        if(all_biger==true){
            A.erase(A.begin()+i);
            i--;
        }
    }

    return answer;
}
*/
int main() {

    vector<int> a = { 5,1,3,7 };
    vector<int> b = { 2,2,6,8 };

    cout << solution(a, b) << endl;


    return 0;
}