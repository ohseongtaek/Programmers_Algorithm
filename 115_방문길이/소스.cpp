#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int solution(string dirs) {

    int borad[10][10][10][10]; // 전x 전y 후x 후y

    // 초기 x,y 좌표
    int pos_x = 5;
    int pos_y = 5;

    // 지나간 길 ++
    int road = 0;

    // 문자열 "" 일때까지
    while (!dirs.empty()) {

        // 첫번째 글자 가져오기
        char temp = dirs[0];
        //cout << temp << endl;
        // up 일때 y++
        if (temp == 'U') {
            // 범위 초과하는지 확인초과하면 그냥 무시
            if (pos_y < 10) {
                // 이전 x,y 에서 이동한 x,y 의 이력이 있는지 확인
                if (borad[pos_x][pos_y][pos_x][pos_y + 1] != 1) {
                    // 이력이 없으면 1로 set
                    borad[pos_x][pos_y][pos_x][pos_y + 1] = 1;
                    // 반대로도 이동해도 road 값은 변하지 않기 때문에 이것도 1로 set
                    borad[pos_x][pos_y + 1][pos_x][pos_y] = 1;
                    // 이후 road++
                    road++;
                }
                pos_y++;
            }
        }

        // down 일때 y--
        else if (temp == 'D') {
            if (pos_y > 0) {
                if (borad[pos_x][pos_y][pos_x][pos_y - 1] != 1) {
                    borad[pos_x][pos_y][pos_x][pos_y - 1] = 1;
                    borad[pos_x][pos_y - 1][pos_x][pos_y] = 1;
                    road++;
                }
                pos_y--;
            }
        }

        // right 일때 x++
        else if (temp == 'R') {
            if (pos_x < 10) {
                if (borad[pos_x][pos_y][pos_x + 1][pos_y] != 1) {
                    borad[pos_x][pos_y][pos_x + 1][pos_y] = 1;
                    borad[pos_x + 1][pos_y][pos_x][pos_y] = 1;
                    road++;
                }
                pos_x++;
            }
        }

        // left 일때 x--
        else if (temp == 'L') {
            if (pos_x > 0) {
                if (borad[pos_x][pos_y][pos_x - 1][pos_y] != 1) {
                    borad[pos_x][pos_y][pos_x - 1][pos_y] = 1;
                    borad[pos_x - 1][pos_y][pos_x][pos_y] = 1;
                    road++;
                }
                pos_x--;
            }
        }

        // 문자열 맨앞 delete
        //cout << "x ? " << pos_x << " y ? " << pos_y << "   road?????  " << road << endl;
        dirs.erase(0, 1);
    }

    return road;
}



int main() {

    string s = "LULLLLLLU";
    int a = solution(s);
    cout << a << endl;
    return 0;

}