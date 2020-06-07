#include <iostream>
using namespace std;
void star(int i, int j, int num)
{
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';                    // 빈공간에 대한 것 
    }
    else
    {
        if (num / 3 == 0)               // 3으로 나눈 몫이 없을때 즉 0일때 num은 0,1,2
            cout << '*';
        else
            star(i, j, num / 3);        // 처음에는 무조건 여기 분기를 탄다 3으로 나눈 몫을 넘긴다 3일때도  
    }
}
int main() {                // 규칙 : 3일때 빈공간은 (1,1) 9일때는 빈공간은 1,1 1,4 1,7 4,1 4,4 4,7 7,1 7,4 7,7 는 기본적으로 빈공간이며 345,345는 모두 빈공간 이는 해당 값을 3으로 나누고 몫을 나머지로 했을때 1이면 빈공간이다 
    int num;
    cin >> num;                     // 3의 배수 입력 
    for (int x = 0; x < num; x++)   // 행반복
    {
        for (int y = 0; y < num; y++)   //열반복 
            star(x, y, num);        // 함수 호출 
        cout << '\n';
    }
}