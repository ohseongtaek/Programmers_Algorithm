#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

// x , y , 기둥보 , 설치미설치 
int visit[101][101][2];
int board_size;

bool Check_range(int x, int y)
{
    if (x <0 || y<0 || x>board_size || y>board_size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool func_install(int x, int y, bool st)
{
    // 기둥
    if (st == 0)
    {
        // 바닥에 설치하는 경우 무조건 설치 및 배열 값 추가 
        if (y == 0)
        {
           return true;
        }
        // 바닥이 아닌 위에 설치하는 경우 보 또는 기둥이 있는지 확인해야함 
        else
        {
            // 오른쪽으로 뻗은 보가 있는 경우 
            if (visit[x][y][1] == true)
            {
                return true;
            }

            // 바로 아래에 기둥이 있는 경우 
            if (visit[x][y - 1][0] == true && Check_range(x,y-1))
            {
                return true;
            }

            // 아래에 보가 있는 경우 
            else if (visit[x - 1][y][1] == true && Check_range(x-1,y))
            {
                return true;
            }
        }
    }
    // 보
    else
    {
        // 보를 설치하려는 곳에 한쪽에 기둥이 있거나 or 둘 다 보가 있거나 둘중 하나임 !
        // 한쪽에 기둥이 있는 경우 (왼쪽)
        if (visit[x][y - 1][0] == true && Check_range(x,y-1))
        {
            return true;
        }
        // 한쪽에 기둥이 있는 경우 (오른쪽)
        else if (visit[x + 1][y - 1][0] == true && Check_range(x+1,y-1))
        {
            return true; 
        }
        // 양쪽에 보가 있는 경우 
        else if (Check_range(x-1,y) && visit[x-1][y][1] == true && Check_range(x+1,y) &&visit[x+1][y][1] == true)
        {
            return true;
        }
    }
    return false;
}

bool func_uninstall()
{
    // 전체 보드에 대해서 하나씩 삭제해보고 확인해보기 -> 처음에 개인 좌표로 했을때 실패함 그 이후 질문하기에서 전체 케이스 확인이 필요하다는것을 알음 Why?
    for (int i = 0; i <= board_size; i++)
    {
        for (int j = 0; j <= board_size; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                // 보 또는 기둥이 존재할때 
                if (visit[i][j][k] == true)
                {
                    // 삭제 한 이후에 
                    visit[i][j][k] = false;

                    // 설치가 가능한지 확인!
                    if (false == func_install(i, j, k))
                    {
                        //불가능할 경우 
                        visit[i][j][k] = true;
                        return false;
                    }
                    
                    visit[i][j][k] = true;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    // 0 으로 전체 배열 초기화 
    memset(visit, 0, sizeof(visit));

    // n : 벽면의 크기 
    board_size = n;
    // build_frame : 배열 항목
    // 0 => x좌표 
    // 1 => y좌표 
    // 2 => 기둥과 보 (0:기둥,1:보)
    // 3 => 설치삭제 (0:삭제, 1:설치)

    // 기둥을 위로 쌓아올림 
    // 보는 오른쪽으로 연결함 (한쪽이 무조건 기둥이거나, 양쪽 모두 보가 있는 경우에 가능함)
    
    for (int i = 0; i < build_frame.size(); i++)
    {
        int pos_x = build_frame[i][0];
        int pos_y = build_frame[i][1];
        int structor = build_frame[i][2];
        int install = build_frame[i][3];

        // 설치하는 로직인 경우 
        if (install == 1)
        {
            if (true == func_install(pos_x, pos_y, structor))
            {
                // 설치 가능하고 기둥일때 
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                // 설치 가능하고 보일때 
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
        // 삭제하는 로직인 경우 
        else
        {
            // 일단 선 삭제 
            if (structor == 0)
            {
                visit[pos_x][pos_y][0] = false;
            }
            else
            {
                visit[pos_x][pos_y][1] = false;
            }
            // 삭제가 불가능이면 원복 
            if (false == func_uninstall())
            {
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                vector<int> v;
                if (visit[i][j][k] == true)
                {
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    answer.push_back(v);
                }
            }
        }
    }

    return answer;
}
int main() {
    int n = 5;
    vector<vector<int>> v = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    vector<vector<int>> v2 = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> a;
    a = solution(n, v);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

/*
삭제 로직 오류
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

// x , y , 기둥보 , 설치미설치
int visit[101][101][2];
int board_size;

bool Check_range(int x, int y)
{
    if (x <0 || y<0 || x>board_size || y>board_size)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool func_install(int x, int y, bool st)
{
    // 기둥
    if (st == 0)
    {
        // 바닥에 설치하는 경우 무조건 설치 및 배열 값 추가
        if (y == 0)
        {
           return true;
        }
        // 바닥이 아닌 위에 설치하는 경우 보 또는 기둥이 있는지 확인해야함
        else
        {
            // 바로 아래에 기둥이 있는 경우
            if (visit[x][y - 1][0] == true && Check_range(x,y-1))
            {
                return true;
            }
            // 아래에 보가 있는 경우
            else if (visit[x - 1][y][1] == true && Check_range(x-1,y))
            {
                return true;
            }
        }
    }
    // 보
    else
    {
        // 보를 설치하려는 곳에 한쪽에 기둥이 있거나 or 둘 다 보가 있거나 둘중 하나임 !
        // 한쪽에 기둥이 있는 경우 (왼쪽)
        if (visit[x][y - 1][0] == true && Check_range(x,y-1))
        {
            return true;
        }
        // 한쪽에 기둥이 있는 경우 (오른쪽)
        else if (visit[x + 1][y - 1][0] == true && Check_range(x+1,y-1))
        {
            return true;
        }
        // 양쪽에 보가 있는 경우
        else if (Check_range(x-1,y) && visit[x-1][y][1] == true && Check_range(x+1,y) &&visit[x+1][y][1] == true)
        {
            return true;
        }
    }
    return false;
}

bool func_uninstall(int x, int y, bool st)
{
    // 기둥 삭제
    if (st == 0)
    {
        // 삭제하려는 기둥위에 기둥이 있는 경우
        if (visit[x][y + 1][0] == true && Check_range(x,y+1))
        {
            // 기둥이 있지만 양 옆에 보가 한개라도 있는경우 삭제 가능
            if ((visit[x - 1][y + 1][1] == true && Check_range(x-1,y+1)) || (visit[x][y + 1][1] == true && Check_range(x,y+1)))
            {
                return true;
            }
        }
        // 삭제하려는 기둥위에 기둥이 없는 경우
        else
        {
            // 보는 있는 경우
            if ((visit[x - 1][y + 1][1] == true && Check_range(x-1,y+1)) || (visit[x][y + 1][1] == true && Check_range(x,y+1)))
            {
                return true;
            }
            // 아무것도 없는 경우 삭제 불가
            else
            {
                return false;
            }
        }
    }
    // 보 삭제
    else
    {
        bool left = false;
        bool right = false;
        // 왼쪽 보에 기둥 있는지 확인
        if((visit[x][y-1][0] == true && Check_range(x,y-1))|| (visit[x-1][y-1][0] == true && Check_range(x-1,y-1)))
        {
            left = true;
        }
        // 오른쪽 보에 기둥이 있는지 확인하기
        if ((visit[x + 1][y - 1][0] == true && Check_range(x+1,y-1)) || visit[x + 2][y - 1][0] == true && Check_range(x+2,y-1))
        {
            right = true;
        }

        // 삭제
        if (left == true && right == true)
        {
            return true;
        }
        // 미 삭제
        else
        {
            return false;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    // 0 으로 전체 배열 초기화
    memset(visit, 0, sizeof(visit));

    // n : 벽면의 크기
    board_size = n;
    // build_frame : 배열 항목
    // 0 => x좌표
    // 1 => y좌표
    // 2 => 기둥과 보 (0:기둥,1:보)
    // 3 => 설치삭제 (0:삭제, 1:설치)

    // 기둥을 위로 쌓아올림
    // 보는 오른쪽으로 연결함 (한쪽이 무조건 기둥이거나, 양쪽 모두 보가 있는 경우에 가능함)

    for (int i = 0; i < build_frame.size(); i++)
    {
        int pos_x = build_frame[i][0];
        int pos_y = build_frame[i][1];
        int structor = build_frame[i][2];
        int install = build_frame[i][3];

        // 설치하는 로직인 경우
        if (install == 1)
        {
            if (true == func_install(pos_x, pos_y, structor))
            {
                // 설치 가능하고 기둥일때
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                // 설치 가능하고 보일때
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
        // 삭제하는 로직인 경우
        else
        {
            // 일단 선 삭제
            if (structor == 0)
            {
                visit[pos_x][pos_y][0] = false;
            }
            else
            {
                visit[pos_x][pos_y][1] = false;
            }
            // 삭제가 불가능이면 원복
            if (false == func_uninstall(pos_x, pos_y, structor))
            {
                if (structor == 0)
                {
                    visit[pos_x][pos_y][0] = true;
                }
                else
                {
                    visit[pos_x][pos_y][1] = true;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                vector<int> v;
                if (visit[i][j][k] == true)
                {
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    answer.push_back(v);
                }
            }
        }
    }

    return answer;
}
int main() {
    int n = 5;
    vector<vector<int>> v = { {1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    vector<vector<int>> v2 = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    vector<vector<int>> a;
    a = solution(n, v);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


*/