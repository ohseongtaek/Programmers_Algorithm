#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) 
{
    int x1 = dots[0][0];
    int y1 = dots[0][1];
    int x2 = dots[1][0];
    int y2 = dots[1][1];
    int x3 = dots[2][0];
    int y3 = dots[2][1];
    int x4 = dots[3][0];
    int y4 = dots[3][1];

    double slope1 = abs((y2 - y1) / static_cast<double>(x2 - x1));
    double slope2 = abs((y4 - y3) / static_cast<double>(x4 - x3));

    double slope3 = abs((y3 - y1) / static_cast<double>(x3 - x1));
    double slope4 = abs((y4 - y2) / static_cast<double>(x4 - x2));

    if (abs(slope1 - slope2) == 0 || abs(slope3 - slope4) == 0) 
    {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    solution({ {1, 5},{1, 4},{2, 6},{2, 9} });
}