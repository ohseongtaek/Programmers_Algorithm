#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        int input = max(i/n, i%n);
        answer.push_back(input + 1);
    }
    
    return answer;
}

int main()
{
    vector<int> dab = solution(3, 2, 5);
    for (int i = 0; i < dab.size(); i++)
    {
        cout << dab[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
n	left	right	result
3	2	    5       [3, 2, 2, 3]
4	7	    14      [4, 3, 3, 3, 4, 4, 4, 4]
*/