#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int row;
int column;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int visit[502][502];
int GroupCount = 1;
vector<vector<int>> v;
map<int, int> m;

void getBFSGroupBlock(int x, int y)
{
    int GroupBlockSize = 0;
    queue<pair<int, int>> qp;
    v[x][y] = GroupCount;
    visit[x][y] = true;
    qp.push(make_pair(x, y));

	while (!qp.empty())
	{
		int tx = qp.front().first;
		int ty = qp.front().second;
		qp.pop();

		GroupBlockSize++;

		for (int i = 0; i < 4; i++)
		{
			int cx = tx + dx[i];
			int cy = ty + dy[i];

			if (cx < 0 || cy < 0 || cx >= row || cy >= column || visit[cx][cy] >= 1 || v[cx][cy] == 0)
			{
				continue;
			}
			else
			{
				v[cx][cy] = GroupCount;
				visit[cx][cy] = true;
				qp.push(make_pair(cx, cy));
			}
		}
	}

    m[GroupCount++] = GroupBlockSize;
}

int solution(vector<vector<int>> land) 
{
    int answer = 0;
    int tmpanswer = 0;
    row = land.size();
    column = land[0].size();
    memset(visit, 0, sizeof(visit));
    v = land;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (visit[i][j] == 0 && v[i][j] > 0)
            {
                getBFSGroupBlock(i, j);
            }
        }
    }
    /*
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    */

    // 시간초과코드 
    /*
    for (int i = 0; i < column; i++)
    {
        tmpanswer = 0;
        vResult.clear();
        for (int j = 0; j < row; j++)
        {
            vResult.push_back(v[j][i]);
        }

        sort(vResult.begin(), vResult.end());


        vResult.erase(unique(vResult.begin(), vResult.end()), vResult.end());

        for (int k = 0; k < vResult.size(); k++)
        {
            tmpanswer += m[vResult[k]];
        }

        answer = max(answer, tmpanswer);
    }
    */

    for (int i = 0; i < column; i++) 
    {
        int temp = 0;
        set<int> s; // set으로 어떤 석유덩어리를 얻었는지 확인
        for (int j = 0; j < row; j++) 
        {
            s.insert(v[j][i]);
        }
        for (auto it : s) {
            temp += m[it];
        }
        answer = max(answer, temp);
    }

    return answer;
}

int main()
{
    vector<vector<vector<int>>> v = { {  {0, 0, 0, 1, 1, 1, 0, 0}, 
                                         {0, 0, 0, 0, 1, 1, 0, 0}, 
                                         {1, 1, 0, 0, 0, 1, 1, 0}, 
                                         {1, 1, 1, 0, 0, 0, 0, 0}, 
                                         {1, 1, 1, 0, 0, 0, 1, 1}},
                                    
                                       { {1, 0, 1, 0, 1, 1}, 
                                         {1, 0, 1, 0, 0, 0}, 
                                         {1, 0, 1, 0, 0, 1}, 
                                         {1, 0, 0, 1, 0, 0}, 
                                         {1, 0, 0, 1, 0, 1}, 
                                         {1, 0, 0, 0, 0, 0}, 
                                         {1, 1, 1, 1, 1, 1}} };
    
    vector<int> d = { 9,16 };
    for (int i = 0; i < v.size(); i++)
    {
        int dab = solution(v[i]);
        if (dab == d[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
        }
    }
}

