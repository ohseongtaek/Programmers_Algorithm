#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) 
{
    int x1 = dots[0][0], y1 = dots[0][1];
    int x2 = dots[1][0], y2 = dots[1][1];
    int x3 = dots[2][0], y3 = dots[2][1];
    int x4 = dots[3][0], y4 = dots[3][1];

    int width = max(x1, max(x2, max(x3, x4))) - min(x1, min(x2, min(x3, x4)));
    int height = max(y1, max(y2, max(y3, y4))) - min(y1, min(y2, min(y3, y4)));

    return width * height;
}

int main()
{
    solution({ {1,2},{2,1},{2,2},{1,2} });
}