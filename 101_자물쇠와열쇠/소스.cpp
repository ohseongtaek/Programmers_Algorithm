#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int key_board_size;
int lock_board_size;
int full_board_size;


void Route(vector<vector<int>>& key) {
    vector<vector<int>> temp(key_board_size, vector<int>(key_board_size, 0));

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key[i].size(); j++) {
            temp[i][j] = key[j][key_board_size - 1 - i];
            //cout << temp[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;
    key = temp;
}

bool Move(int x, int y, vector<vector<int>> board, vector<vector<int>> key) {
    int x_top = x + key_board_size;
    int y_top = y + key_board_size;

    // full board 에 key 값을 넣는다
    for (int i = x; i < x_top; i++) {
        for (int j = y; j < y_top; j++) {
            board[i][j] += key[i - x][j - y];
        }
    }

    /* debug code
    cout << endl;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            cout << board[i][j] <<"   ";
        }
        cout << endl;
    }
    cout << endl;
    */

    // full board 에서 lock 이 들어있는 곳이 모두 1인지 확인한다.
    for (int i = key_board_size - 1; i <= full_board_size - key_board_size; i++) {
        for (int j = key_board_size - 1; j <= full_board_size - key_board_size; j++) {
            if (board[i][j] == 1) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    key_board_size = key.size();
    lock_board_size = lock.size();

    // 전체 보드의 한변의 길이
    full_board_size = 2 * (key_board_size - 1) + lock_board_size;

    // 전체 보드를 0으로 초기화
    vector<vector<int>> full_board(full_board_size, vector<int>(full_board_size, 0));

    // Lock 배열만 full_board 에 채우기
    for (int i = key_board_size - 1; i <= full_board_size - key_board_size; i++) {
        for (int j = key_board_size - 1; j <= full_board_size - key_board_size; j++) {
            full_board[i][j] = lock[i - key_board_size + 1][j - key_board_size + 1];
        }
    }

    /* debug code
    for(int i=0; i<full_board.size(); i++){
        for(int j=0; j<full_board[i].size(); j++){
            cout << full_board[i][j] <<"   ";
        }
        cout << endl;
    }
    */

    bool flag = false;

    // 처음에 왼쪽위 모서리부터 lock 오른쪽아래 모서리까지 쭉 이동하고 없으면 route 함수를 만나 90도 회전
    for (int R = 0; R < 4; R++) {
        for (int i = 0; i <= full_board_size - key_board_size; i++) {
            for (int j = 0; j <= full_board_size - key_board_size; j++) {
                flag = Move(i, j, full_board, key);
                if (flag == true) {
                    return true;
                }
            }
        }
        //90 도 회전 함수
        Route(key);
    }
    return answer;
}

int main() {
    vector<vector<int>> k = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
    vector<vector<int>> l = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    bool d = solution(k, l);
    cout << d << endl;
}