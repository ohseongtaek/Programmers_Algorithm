#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<pair<int,int>> CheckDist(vector<pair<int, int>> vp)
{
    vector<pair<int,int>> idx;

    for (int i = 0; i < vp.size()-1; i++)
    {
        for (int j = i + 1; j < vp.size(); j++)
        {
            int dist = abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second);
            if (dist <= 2)
            {
                idx.push_back(make_pair(vp[i].first, vp[i].second));
                idx.push_back(make_pair(vp[j].first, vp[j].second));
            }
        }
    }
    return idx;
}

bool LoopPartX(int x, int x1, int y, vector<string> vec)
{
    bool answer = false;
    while (1)
    {
        if (x == x1)
        {
            break;
        }
        x++;
        if (vec[x][y] == 'X')
        {
            answer = true;
            break;
        }
    }
    return answer;
}
bool LoopPartY(int y, int y1, int x, vector<string> vec)
{
    bool answer = false;
    while (1)
    {
        if (y == y1)
        {
            break;
        }
        y++;
        if (vec[x][y] == 'X')
        {
            answer = true;
            break;
        }
    }
    return answer;
}
bool LoopPartXY(int x, int x1, int y, int y1, vector<string> vec)
{
    bool answer = false;
    bool check1 = false;
    bool check2 = false;

    if (x < x1 && y < y1)
    {
        if (vec[x][y + 1] == 'X')
        {
            check1 = true;
        }
        if (vec[x1][y1 - 1] == 'X')
        {
            check2 = true;
        }
        if (check1 && check2)
        {
            answer = true;
        }
    }
    else
    {
        if (vec[x][y - 1] == 'X')
        {
            check1 = true;
        }
        if (vec[x1][y1 + 1] == 'X')
        {
            check2 = true;
        }
        if (check1 && check2)
        {
            answer = true;
        }
    }
    return answer;
}

bool CheckPartion(vector<pair<int, int>> vp, vector<string> vecPart)
{
    bool answer = true;
    bool bPartExist = false;

    for (int i = 0; i < vp.size(); i=i+2)
    {
        int x, x1, y, y1;
        x = vp[i].first;
        y = vp[i].second;
        x1 = vp[i + 1].first;
        y1 = vp[i + 1].second;

        //대각선
        if (x != x1 && y != y1)
        {
            bPartExist = LoopPartXY(x, x1, y, y1, vecPart);
        }
        //세로
        else if (x != x1 && y == y1)
        {
            if (x > x1)
            {
                bPartExist = LoopPartX(x1, x, y, vecPart);
            }
            else
            {
                bPartExist = LoopPartX(x, x1, y, vecPart);
            }
        }
        //가로
        else if (x == x1 && y != y1)
        {
            if (y > y1)
            {
                bPartExist = LoopPartY(y1, y, x, vecPart);
            }
            else
            {
                bPartExist = LoopPartY(y, y1, x, vecPart);
            }
        }

        if (bPartExist == false)
        {
            answer = false;
            break;
        }
    }


    return answer;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<vector<char>> v;
    vector<pair<int, int>> vecPersonPos;
    vector<string> vecStr;
    
    for (int i = 0; i < places.size(); i++)
    {
        bool ans = true;
        v.clear();
        vecPersonPos.clear();
        vecStr.clear();
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].size(); k++)
            {
                if (places[i][j][k] == 'P')
                {
                    vecPersonPos.push_back(make_pair(j, k));
                }
            }
            vecStr.push_back(places[i][j]);
        }

        if (vecPersonPos.size() == 0)
        {
            answer.push_back(ans);
        }
        else
        {
            vector<pair<int, int>> vecResultDist = CheckDist(vecPersonPos);
            ans = CheckPartion(vecResultDist, vecStr);
            answer.push_back(ans);
        }
    }
    return answer;
}

int main()
{
    vector<vector<string>> a = { {"POOOP", 
                                  "OXXOX", 
                                  "OPXPX", 
                                  "OOXOX", 
                                  "POXXP"},

                                 {"POOPX", 
                                  "OXPXP", 
                                  "PXXXO", 
                                  "OXXXO", 
                                  "OOOPP"},

                                 {"PXOPX", 
                                  "OXOXP", 
                                  "OXPOX", 
                                  "OXXOP", 
                                  "PXPOX"},

                                 {"OOOXX", 
                                  "XOOOX", 
                                  "OOOXX", 
                                  "OXOOX", 
                                  "OOOOO"},

                                 {"PXPXP", 
                                  "XPXPX", 
                                  "PXPXP", 
                                  "XPXPX", 
                                  "PXPXP"} };

    vector<int> dab = solution(a);
    for (int i = 0; i < dab.size(); i++)
    {
        cout << dab[i] << " ";
    }
}