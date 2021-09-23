#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string AvgSum(vector<int> sum, int exception_idx, bool duplicated)
{
    string answer = "";
    int avg = 0;
    int hap = 0;

    for (int i = 0; i < sum.size(); i++)
    {
        if (duplicated == true)
        {
            hap += sum[i];
        }
        else
        {
            if (i == exception_idx)
            {
                continue;
            }
            else
            {
                hap += sum[i];
            }
        }
        cout << sum[i] << " ";
    }
    cout << endl;
    cout << hap << endl;
    
    if (duplicated == true)
    {
        avg = hap / sum.size();
    }
    else
    {
        avg = hap / (sum.size() - 1);
    }

    cout << avg << endl;
        
    if (avg >= 90)
    {
        answer = 'A';
    }
    else if (avg >= 80)
    {
        answer = 'B';
    }
    else if (avg >= 70)
    {
        answer = 'C';
    }
    else if (avg >= 50)
    {
        answer = 'D';
    }
    else 
    {
        answer = 'F';
    }

    return answer;
}

string solution(vector<vector<int>> scores) {
    string answer = "";

    for (int i = 0; i < scores.size(); i++)
    {
        vector<int> sum;
        int my_score = 0;
        int dup_count = 0;
        int ExceptionIdx = -1;
        bool EndPoint = false;
        bool duplicated = false;

        for (int j = 0; j < scores[i].size(); j++)
        {
            sum.push_back(scores[j][i]);
            if (i == j)
            {
                my_score = scores[j][i];
            }
        }

        sort(sum.begin(), sum.end());

        for (int j = 0; j < sum.size(); j++)
        {
            if (my_score == sum[j])
            {
                dup_count++;
                if (dup_count >= 2)
                {
                    duplicated = true;
                }

                if (j == 0 || 
                    j == sum.size() - 1)
                {
                    EndPoint = true;
                    ExceptionIdx = j;
                }
            }
        }

        if (duplicated == true)
        {
            answer += AvgSum(sum, ExceptionIdx, true);
        }
        else
        {
            if (EndPoint == true)
            {
                answer += AvgSum(sum, ExceptionIdx, false);
            }
            else
            {
                answer += AvgSum(sum, ExceptionIdx, true);
            }
            
        }
        sum.clear();
    }

    return answer;
}

int main()
{
    vector<vector<int>> s = { {70,49,90},
                                {68,50,38},
                                {73,31,100} };
                                

    string a = solution(s);

    cout << a << endl;
}