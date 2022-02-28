#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

// 최대 100x100 사이즈 및 방향 저장 배열 
bool visit[101][101][4];

// 방향 위치 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


// 방향이 변경되는것 
int ChangeDir(int Dir)
{
    if (Dir == 0)
        return 1;
    else if (Dir == 1)
        return 0;
    else if (Dir == 2)
        return 3;
    else if (Dir == 3)
        return 2;
}


// BFS 문제 Queue 사용 후 최단거리 확보 
int solution(vector<vector<int>> board) {
    int answer = 0;
    
    // 위치 지정할 구조체 
    struct POS
    {
        int x, y, dir, cnt;
        // Dir = 0,1,2,3 (동서남북)
    };

    // 전체 범위 
    int range_N = board.size();

    // BFS Create Queue
    queue<POS> q;
    // 오른쪽에 있는 것을 기준점으로 하고 
    q.push({ 0,1,1,0 });
    // 0,0 에 있으며 다른 하나가 동쪽을 방문한것으로 체크 
    visit[0][0][0] = true;
    // 0,1 에 있으며 다른 하나가 서쪽을 방문한것으로 체크 
    visit[0][1][1] = true;

    // 큐가 모두 사라질때 까지 반복 
    while (q.empty() == 0)
    {
        // pos_x pos_y 종착역에 가까운 좌표 
        int pos_x = q.front().x;
        int pos_y = q.front().y;
        int pos_dir = q.front().dir;
        int pos_cnt = q.front().cnt;

        // pos_xx pos_yy 종착역에서 먼 좌표 
        int pos_xx = pos_x + dx[pos_dir];
        int pos_yy = pos_y + dy[pos_dir];

        // 큐 하나 제거 
        q.pop();

        // 위치중 하나라도 범위가 넘어갈 경우 
        if ((pos_x == range_N - 1 && pos_y == range_N - 1) || (pos_xx == range_N - 1 && pos_yy == range_N - 1))
        {
            return pos_cnt;
        }

        // 동서남북 인적한 맵 전체 탐색 
        for (int i = 0; i < 4; i++)
        {
            if (pos_dir == i)
            {
                int pos_change_x = pos_xx + dx[i];
                int pos_change_y = pos_yy + dy[i];
                if (pos_change_x >= 0 && pos_change_y >= 0 && pos_change_x < range_N && pos_change_y < range_N)
                {
                    if (board[pos_change_x][pos_change_y] == 0 && visit[pos_change_x][pos_change_y][ChangeDir(pos_dir)] == false && visit[pos_xx][pos_yy][pos_dir] == false)
                    {
                        visit[pos_x][pos_y][ChangeDir(pos_dir)] = true;
                        visit[pos_xx][pos_yy][pos_dir] = true;
                        q.push({pos_xx,pos_yy,pos_dir,pos_cnt+1});
                    }
                }
            }
            else if (ChangeDir(pos_dir) == i)
            {
                int pos_change_x = pos_x + dx[i];
                int pos_change_y = pos_y + dy[i];
                if (pos_change_x >= 0 && pos_change_y >= 0 && pos_change_x < range_N && pos_change_y < range_N)
                {
                    if (board[pos_change_x][pos_change_y] == 0 && visit[pos_change_x][pos_change_y][pos_dir] == false && visit[pos_x][pos_y][ChangeDir(pos_dir)] == false)
                    {
                        visit[pos_change_x][pos_change_y][pos_dir] = true;
                        visit[pos_x][pos_y][ChangeDir(pos_dir)] = true;
                        q.push({ pos_change_x,pos_change_y,pos_dir,pos_cnt + 1 });
                    }
                }
            }
            else
            {
                int pos_change_x = pos_x + dx[i];
                int pos_change_y = pos_y + dy[i];
                int pos_change_xx = pos_xx + dx[i];
                int pos_change_yy = pos_yy + dy[i];
                if (pos_change_x >= 0 && pos_change_y >= 0 && pos_change_x < range_N && pos_change_y < range_N && pos_change_xx >= 0 && pos_change_yy >= 0 && pos_change_xx < range_N && pos_change_yy < range_N)
                {
                    if (board[pos_change_x][pos_change_y] == 0 && board[pos_change_xx][pos_change_yy] == 0)
                    {
                        if (visit[pos_change_x][pos_change_y][pos_dir] == false && visit[pos_change_xx][pos_change_yy][ChangeDir(pos_dir)] == false)
                        {
                            visit[pos_change_x][pos_change_y][pos_dir] = true;
                            visit[pos_change_xx][pos_change_yy][ChangeDir(pos_dir)] = true;
                            q.push({ pos_change_x,pos_change_y,pos_dir,pos_cnt + 1 });
                        }
                    }
                }
            }
        }

        // 동쪽 혹은 서쪽인 경우 
        if (pos_dir == 0 || pos_dir == 1)
        {
            //서쪽
            int temp_x = pos_x - 1;
            int temp_xx = pos_xx - 1;
            if (temp_x >= 0 && temp_xx >= 0 && temp_x < range_N && temp_xx < range_N)
            {
                // 갈 수 있는 경우 
                if (board[temp_x][pos_y] == 0 && board[temp_xx][pos_yy] == 0)
                {
                    if (visit[pos_x][pos_y][3] == false && visit[temp_x][pos_y][2] == false)
                    {
                        visit[pos_x][pos_y][3] = true;
                        visit[temp_x][pos_y][2] = true;
                        q.push({ pos_x,pos_y,3,pos_cnt + 1 });
                    }
                    if (visit[temp_xx][pos_yy][2] == false && visit[pos_xx][pos_yy][3] == false)
                    {
                        visit[temp_xx][pos_yy][2] = true;
                        visit[pos_xx][pos_yy][3] = true;
                        q.push({ temp_xx,pos_yy,2,pos_cnt + 1 });
                    }
                }
            }
            //동쪽
            temp_x = pos_x + 1;
            temp_xx = pos_xx + 1;
            if (temp_x >= 0 && temp_xx >= 0 && temp_x < range_N && temp_xx < range_N)
            {
                if (board[temp_x][pos_y] == 0 && board[temp_xx][pos_yy] == 0)
                {
                    if (visit[pos_x][pos_y][2] == false && visit[temp_x][pos_y][3] == false)
                    {
                        visit[pos_x][pos_y][2] = true;
                        visit[temp_x][pos_y][3] = true;
                        q.push({ pos_x, pos_y, 2, pos_cnt + 1 });
                    }

                    if (visit[temp_xx][pos_yy][3] == false && visit[pos_xx][pos_yy][2] == false)
                    {
                        visit[temp_xx][pos_yy][3] = true;
                        visit[pos_xx][pos_yy][2] = true;
                        q.push({ temp_xx, pos_yy, 3, pos_cnt + 1 });
                    }
                }
            }
        }
        // 남 혹은 북인경우 
        else
        {
            int temp_y = pos_y - 1;
            int temp_yy = pos_yy - 1;
            if (temp_y >= 0 && temp_yy >= 0 && temp_y < range_N && temp_yy < range_N)
            {
                if (board[pos_x][temp_y] == 0 && board[pos_xx][temp_yy] == 0)
                {
                    if (visit[pos_x][pos_y][1] == false && visit[pos_x][temp_y][0] == false)
                    {
                        visit[pos_x][pos_y][1] = true;
                        visit[pos_x][temp_y][0] = true;
                        q.push({ pos_x, pos_y, 1, pos_cnt + 1 });
                    }

                    if (visit[pos_xx][pos_yy][1] == false && visit[pos_xx][temp_yy][0] == false)
                    {
                        visit[pos_xx][pos_yy][1] = true;
                        visit[pos_xx][temp_yy][0] = true;
                        q.push({ pos_xx, temp_yy, 0, pos_cnt + 1 });
                    }
                }
            }

            temp_y = pos_y + 1;
            temp_yy = pos_yy + 1;
            if (temp_y >= 0 && temp_yy >= 0 && temp_y < range_N && temp_yy < range_N)
            {
                if (board[pos_x][temp_y] == 0 && board[pos_xx][temp_yy] == 0)
                {
                    if (visit[pos_x][pos_y][0] == false && visit[pos_x][temp_y][1] == false)
                    {
                        visit[pos_x][pos_y][0] = true;
                        visit[pos_x][temp_y][1] = true;
                        q.push({ pos_x, pos_y, 0, pos_cnt + 1 });
                    }

                    if (visit[pos_xx][pos_yy][0] == false && visit[pos_xx][temp_yy][1] == false)
                    {
                        visit[pos_xx][pos_yy][0] = true;
                        visit[pos_xx][temp_yy][1] = true;
                        q.push({ pos_xx, temp_yy, 1, pos_cnt + 1 });
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>>  vb = { {0, 0, 0, 1, 1}, { 0, 0, 0, 1, 0 }, { 0, 1, 0, 1, 1 }, { 1, 1, 0, 0, 1 }, { 0, 0, 0, 0, 0 } };
    cout << solution(vb) << endl;
}

