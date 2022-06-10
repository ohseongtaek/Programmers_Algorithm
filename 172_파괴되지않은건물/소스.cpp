#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int bord[1002][1002];

void show_bord(vector<vector<int>> board)
{
    int len = board[0].size() + 1;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << bord[i][j] << " ";
        }
        cout << endl;
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;

    /*
    *
    * 효율성 0점 코드 ! => 2차원 배열 누적합 이용 https://tech.kakao.com/2022/01/14/2022-kakao-recruitment-round-1/
    *
    // 보드 최대 크기만큼 0으로 초기화
    memset(bord, 0, sizeof(bord));

    // 보드 값을 기준으로 bord 값 초기화 시켜주기
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            bord[i][j] = board[i][j];
        }
    }

#ifdef _DEBUG
    //show_bord(board);
#endif

    for (int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0];
        int start_y = skill[i][1];
        int start_x = skill[i][2];
        int end_y = skill[i][3];
        int end_x = skill[i][4];
        int degree = skill[i][5];

        if (type == 1)
        {
            for (int j = start_y; j <= end_y; j++)
            {
                for (int k = start_x; k <= end_x; k++)
                {
                    bord[j][k] -= degree;
                }
            }
        }
        else
        {
            for (int j = start_y; j <= end_y; j++)
            {
                for (int k = start_x; k <= end_x; k++)
                {
                    bord[j][k] += degree;
                }
            }
        }

        //show_bord(board);
        //cout << endl;
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (bord[i][j] > 0)
            {
                //cout << i << " " << j << endl;
                answer++;
            }
        }
    }
    */


    // 배열 전체 초기화 
    memset(bord, 0, sizeof(bord));

    for (int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0];
        int start_y = skill[i][1];
        int start_x = skill[i][2];
        int end_y = skill[i][3];
        int end_x = skill[i][4];
        int degree = skill[i][5];


        // 누적합 이용 
        if (type == 1)
        {
            degree = -degree;
        }
        bord[start_y][start_x] += degree;
        bord[end_y + 1][end_x + 1] += degree;
        bord[start_y][end_x + 1] -= degree;
        bord[end_y + 1][start_x] -= degree;

    }

    // 세로 합 
    for (int i = 0; i < board[0].size() + 1; i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            bord[j + 1][i] += bord[j][i];
        }
        //show_bord(board);
        //cout << endl;
    }

    // 가로 합
    for (int i = 0; i < board.size() + 1; i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            bord[i][j + 1] += bord[i][j];
        }
        //show_bord(board);
        //cout << endl;
    }

    // 기존 board 배열과 합치기 
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] + bord[i][j] > 0)
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<vector<int>>> board = { {{5, 5, 5, 5, 5}, {5, 5, 5, 5, 5}, {5, 5, 5, 5, 5}, {5, 5, 5, 5, 5}},
                                          {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}} };

    vector<vector<vector<int>>> skill = { {{1, 0, 0, 3, 4, 4}, {1, 2, 0, 2, 3, 2}, {2, 1, 0, 3, 1, 2}, {1, 0, 1, 3, 3, 1}},
                                          {{1, 1, 1, 2, 2, 4}, {1, 0, 0, 1, 1, 2}, {2, 2, 0, 2, 0, 100}} };
    vector<int> dab = { 10,6 };

    // skill = type(1:attack,2:recovery) (r1 c1) (r2 c2) degree


    for (int i = 0; i < board.size(); i++)
    {
        int answer = solution(board[i], skill[i]);
        if (answer == dab[i])
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "error answer[" << answer << "] , want[" << dab[i] << "]" << endl;
        }
    }

}
