#include <string>
#include <iostream>
#include <vector>

using namespace std;

int Min_Number;

void diff(int a)
{
    if (Min_Number > a)
    {
        Min_Number = a;
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> table;

    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        vector<int> v;
        for (int j = 0; j < columns; j++)
        {
            v.push_back(value);
            value++;
        }
        table.push_back(v);
    }
    //for (int i = 0; i < table.size(); i++)
    //{
    //    for (int j = 0; j < table[i].size(); j++)
    //    {
    //        cout << table[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    for (int i = 0; i < queries.size(); i++)
    {
        Min_Number = rows * columns;
        int start_x = queries[i][0] - 1;
        int start_y = queries[i][1] - 1;
        int end_x = queries[i][2] - 1;
        int end_y = queries[i][3] - 1;

        int Start_Value = table[start_x][start_y];
        diff(Start_Value);
        
        for (int i = start_x; i < end_x; i++)
        {
            table[i][start_y] = table[i+1][start_y];
            diff(table[i][start_y]);
        }
        for (int i = start_y; i < end_y; i++)
        {
            table[end_x][i] = table[end_x][i+1];
            diff(table[end_x][i]);
        }
        for (int i = end_x; i > start_x; i--)
        {
            table[i][end_y] = table[i - 1][end_y];
            diff(table[i][end_y]);
        }
        for (int i = end_y; i > start_y; i--)
        {
            table[start_x][i] = table[start_x][i - 1];
            diff(table[start_x][i]);
        }

        table[start_x][start_y + 1] = Start_Value;

        //for (int i = 0; i < table.size(); i++)
        //{
        //    for (int j = 0; j < table[i].size(); j++)
        //    {
        //        cout << table[i][j] << " ";
        //    }
        //    cout << endl;
        //}
        //cout << "===============================" << endl;

        answer.push_back(Min_Number);
    }
    return answer;
}


int main()
{
    int r = 6;
    int c = 6;
    vector<vector<int>> q = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };
    vector<int> re = solution(r, c, q);

    for (int i = 0; i < re.size(); i++)
    {
        cout << re[i] << " ";
    }
    cout << endl;

    return 0;
}