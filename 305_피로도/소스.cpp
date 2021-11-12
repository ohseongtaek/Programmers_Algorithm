#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
#include <map>
using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int nTired = 0;
    int nCntDungeons = 0;
    vector<int> v;

    for (int i = 0; i < dungeons.size(); i++) 
    {
        v.push_back(i); 
    }

    do
    {
        nTired = k;
        nCntDungeons = 0;

        for (int i = 0; i < dungeons.size(); i++)
        {
            int nMinTired = dungeons[v[i]][0]; 
            int nUseTired = dungeons[v[i]][1]; 

            if( nMinTired > nTired )
            {
                continue; 
            } 
            nTired = nTired - nUseTired;
            nCntDungeons++;
        }
        answer = max(answer, nCntDungeons);
    } while (next_permutation(v.begin(), v.end()));
  
    return answer;
}

int main()
{
    int a = 80;
    vector<vector<int>> v = { {80, 20},{50, 40},{30, 10} };
    cout << solution(a, v) << endl;
}