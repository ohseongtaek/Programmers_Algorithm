#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    
    vector<long long> VecDwAnswer;
    
    for (long long dwi = 0; dwi < numbers.size(); dwi++)
    {
        long long num = numbers[dwi];
        // Odd
        if (num % 2 != 0)
        {
            long long dwtmp = numbers[dwi];
            int nPosition = 0;
            while (true == (dwtmp & 1))
            {
                dwtmp >>= 1;
                nPosition++;
            }
            //cout << nPosition << endl;
            VecDwAnswer.push_back(num + (pow(2, nPosition) - pow(2, nPosition - 1)));
        }
        // Evne 
        else
        {
            VecDwAnswer.push_back(num + 1);
        }
    }

    return VecDwAnswer;
}

int main()
{
    vector<long long> v = { 19, 35 };
    vector<long long> t = solution(v);
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << endl;
    }

    return 0;
}