#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
두 정수 left와 right가 매개변수로 주어집니다.
left부터 right까지의 모든 수들 중에서,
약수의 개수가 짝수인 수는 더하고,
약수의 개수가 홀수인 수는 뺀 수를
return 하도록 solution 함수를 완성해주세요.
*/

int numberofaddition(int number){
    int count = 0;
    for(int i=1; i<=number; i++){
        if(number%i==0){
            count++;
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;

    for(int i=left; i<=right; i++){
        int addition = numberofaddition(i);
        if(addition%2==0){
            answer += i;
        }
        else{
            answer -= i;
        }
    }
    return answer;
}

int main()
{
    int left = 24;
    int right = 27;
    int dab = solution(left,right);
    cout << dab << endl;
    return 0;
}
/*
13	17	43
24	27	52
*/
