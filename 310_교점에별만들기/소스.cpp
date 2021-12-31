

// int 형 넘어가는거 생각 못함
//#include <string>
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//pair<int, int> Cal(long A, long B, long E, long C, long D, long F)
//{
//    pair<long, long> p;
//    double below = 0;
//    double topX = 0;
//    double topY = 0;
//
//
//    below = (A * D) - (B * C);
//    topX = (B * F) - (E * D);
//    topY = (E * C) - (A * F);
//
//    if (topX == 0)
//    {
//        p.first = 0;
//    }
//    else
//    {
//        p.first = topX / below;
//    }
//
//    if (topY == 0)
//    {
//        p.second = 0;
//    }
//    else
//    {
//        p.second = topY / below;
//    }
//
//    return p;
//}
//
//
//vector<string> solution(vector<vector<int>> line) {
//    vector<string> answer;
//    vector<pair<int, int>> vp;
//
//    int Xmax = 0;
//    int Xmin = 0;
//    int Ymax = 0;
//    int Ymin = 0;
//
//    for (int i = 0; i < line.size(); i++)
//    {
//        int x = line[i][0];
//        int y = line[i][1];
//        int z = line[i][2];
//        for (int j = i; j < line.size(); j++)
//        {
//            if (i == j)
//            {
//                continue;
//            }
//            else
//            {
//                int x1 = line[j][0];
//                int y1 = line[j][1];
//                int z1 = line[j][2];
//
//                // ad-bc = 0 (평행 또는 일치)
//                if (0 == ((x * y1) - (y * x1)))
//                {
//                    continue;
//                }
//                else
//                {
//                    pair<long, long> p = Cal(x, y, z, x1, y1, z1);
//
//                    if (((p.first - (int)p.first) == 0) && ((p.second - (int)p.second) == 0))
//                    {
//                        vp.push_back(p);
//                    }
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < vp.size(); i++)
//    {
//        if (i == 0)
//        {
//            Xmin = Xmax = vp[i].first;
//            Ymin = Ymax = vp[i].second;
//        }
//        else
//        {
//            Xmin = min(Xmin, vp[i].first);
//            Xmax = max(Xmax, vp[i].first);
//            Ymin = min(Ymin, vp[i].second);
//            Ymax = max(Ymax, vp[i].second);
//        }
//    }
//
//    for (int i = Ymin; i <= Ymax; i++)
//    {
//        string temp = "";
//        for (int j = Xmin; j <= Xmax; j++)
//        {
//            bool flag = false;
//            for (int k = 0; k < vp.size(); k++)
//            {
//                if (j == vp[k].first && i == vp[k].second)
//                {
//                    flag = true;
//                    break;
//                }
//            }
//
//            if (flag == true)
//            {
//                temp += '*';
//            }
//            else
//            {
//                temp += '.';
//            }
//        }
//        answer.push_back(temp);
//    }
//
//    reverse(answer.begin(), answer.end());
//
//    return answer;
//}
//
//int main()
//{
//    vector<vector<int>> dot = { {2, -1, 4}, {-2, -1, 4}, { 0, -1, 1}, {5, -8, -12}, {5, 8, 12} };
//    //{ {2, -1, 4}, {-2, -1, 4}, { 0, -1, 1}, {5, -8, -12}, {5, 8, 12} };
//    //{{0, 1, -1}, {1, 0, -1}, {1, 0, 1}}
//
//    //{{1, -1, 0}, {2, -1, 0}}	["*"]
//    //[[1, -1, 0], [2, -1, 0], [4, -1, 0]]
//
//    vector<string> dab = solution(dot);
//
//    for (int i = 0; i < dab.size(); i++)
//    {
//        cout << dab[i] << endl;
//    }
//
//    return 0;
//
//}

#include <string>
#include <vector>
#include <iostream>
#define RANGE 100000001
using namespace std;


// 시작시 메모리 할당 문제로 전역변수 처리 
long long len, Xmin, Ymin, Xmax, Ymax;
void init() {
    Xmax = -RANGE;
    Ymax = -RANGE;
    Xmin = RANGE;
    Ymin = RANGE;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    len = line.size();
    vector<pair<long long, long long>> vp;
    init();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            long long Below = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            if (Below == 0)
            {
                continue;
            }
            long long Xtop = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            long long Ytop = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
            if ((Xtop % Below != 0) || (Ytop % Below != 0))
            {
                continue;
            }
            Xtop = Xtop / Below;
            Ytop = Ytop / Below;
            vp.push_back({ Ytop, Xtop });
            Xmax = max(Xmax, (long long)Xtop);
            Ymax = max(Ymax, (long long)Ytop);
            Xmin = min(Xmin, (long long)Xtop);
            Ymin = min(Ymin, (long long)Ytop);
        }
    }
    long long row = Ymax - Ymin + 1;
    long long col = Xmax - Xmin + 1;
    
    // Answer vector 초기화 
    string temp(col, '.');
    answer.assign(row, temp);

    // 좌표값만 별로 채우기 
    for (int i = 0; i < vp.size(); i++) 
    {
        long long y = vp[i].first;
        long long x = vp[i].second;
        answer[Ymax - y][x - Xmin] = '*';
    }
    return answer;
}