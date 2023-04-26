#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char d[] = { 'd', 'l', 'r', 'u' };
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,-1,1,0 };

string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    string answer = "";

    //Check Impossible 
    int dist = abs(x - r) + abs(y - c);
    if ((dist > k) || ((k - dist) % 2 == 1))
    {
        answer = "impossible";
    }
    else
    {
        while (true)
        {
            k--;
            for (int i = 0; i < 4; i++) 
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nshortest = abs(nx - r) + abs(ny - c);

                if (nx <= 0 || ny <= 0 || nx > n || ny > m || nshortest > k)
                {
                    continue;
                }
                x = nx;
                y = ny;
                answer += d[i];
                break;
            }

            if(k==0)
            {
                break;
            }
        }
    }
    return answer;
}


int main()
{
    vector<int> n = { 3,2,3 };
    vector<int> m = { 4,2,3 };
    vector<int> x = { 2,1,1 };
    vector<int> y = { 3,1,2 };
    vector<int> r = { 3,2,3 };
    vector<int> c = { 1,2,3 };
    vector<int> k = { 5,2,4 };

    vector<string> v = { "dllrl", "dr", "impossible" };

    for (int i = 0; i < n.size(); i++)
    {
        string dab = solution(n[i], m[i], x[i], y[i], r[i], c[i], k[i]);

        if (dab == v[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
        }
    }
}