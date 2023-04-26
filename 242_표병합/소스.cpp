#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_COUNT 2500

int CalIdx(int r, int c) 
{
    return (r - 1) * 50 + c;
}

vector<string> solution(vector<string> commands) 
{
    int* unMergeLinking = new int[2501];
    string* strExcel = new string[2501];
    //int link[2501];
    //string value[2501];
    vector<string> answer;

    for (int i = 1; i <= MAX_COUNT; i++)
    {
        unMergeLinking[i] = i;
        strExcel[i] = "EMPTY";
    }

    for (auto command : commands) 
    {
        vector<string> v;
        stringstream ss(command);
        string token;
        while (ss >> token)
        {
            v.push_back(token);
        }

        if (v[0] == "UPDATE") 
        {
            // 부분 업데이트 
            if (v.size() == 4) 
            {
                string val = v[3];
                int parent = unMergeLinking[CalIdx(stoi(v[1]), stoi(v[2]))];
                strExcel[parent] = val;
            }
            // 전체 업데이트 
            else
            {
                string val1 = v[1];
                string val2 = v[2];
                for (int i = 1; i <= 2500; i++) 
                {
                    if (strExcel[i] == val1)
                    {
                        strExcel[i] = val2;
                    }
                }
            }
        }
        else if (v[0] == "MERGE") 
        { 
            int LeftPar = unMergeLinking[CalIdx(stoi(v[1]), stoi(v[2]))];
            int RightPar = unMergeLinking[CalIdx(stoi(v[3]), stoi(v[4]))];
            
            // 부모(원래있던값) 같지 않은 경우 
            if (LeftPar != RightPar)
            {
                // 부모 값 변경 
                for (int i = 1; i <= 2500; i++) 
                {
                    if (unMergeLinking[i] == RightPar)
                    {
                        unMergeLinking[i] = LeftPar;
                    }
                }

                // 현재 값 변경 
                string LeftCurrentValue = strExcel[LeftPar];
                string RightCurrentValue = strExcel[RightPar];
                if (LeftCurrentValue == "EMPTY" && RightCurrentValue != "EMPTY")
                {
                    strExcel[LeftPar] = strExcel[RightPar];
                }
                else 
                {
                    strExcel[RightPar] = strExcel[LeftPar];
                }
            }
        }
        else if (v[0] == "UNMERGE") 
        { 
            int CurrentIdxPar = unMergeLinking[CalIdx(stoi(v[1]), stoi(v[2]))];
            string val = strExcel[CurrentIdxPar];
            for (int i = 1; i <= 2500; i++) 
            {
                if (unMergeLinking[i] == CurrentIdxPar) 
                {
                    unMergeLinking[i] = i;
                    strExcel[i] = "EMPTY";
                }
            }
            strExcel[CalIdx(stoi(v[1]), stoi(v[2]))] = val;
        }
        else 
        { 
            int parent = unMergeLinking[CalIdx(stoi(v[1]), stoi(v[2]))];
            answer.push_back(strExcel[parent]);
        }
    }

    delete[] unMergeLinking;
    delete[] strExcel;

    return answer;
}

int main()
{
    vector<vector<string>> vv = { { "UPDATE 1 1 menu", 
                                    "UPDATE 1 2 category", 
                                    "UPDATE 2 1 bibimbap", 
                                    "UPDATE 2 2 korean", 
                                    "UPDATE 2 3 rice", 
                                    "UPDATE 3 1 ramyeon", 
                                    "UPDATE 3 2 korean", 
                                    "UPDATE 3 3 noodle", 
                                    "UPDATE 3 4 instant", 
                                    "UPDATE 4 1 pasta",
                                    "UPDATE 4 2 italian", 
                                    "UPDATE 4 3 noodle", 
                                    "MERGE 1 2 1 3", 
                                    "MERGE 1 3 1 4", 
                                    "UPDATE korean hansik", 
                                    "UPDATE 1 3 group", 
                                    "UNMERGE 1 4", 
                                    "PRINT 1 3", 
                                    "PRINT 1 4"} ,
                                    
                                    {   "UPDATE 1 1 a", 
                                        "UPDATE 1 2 b", 
                                        "UPDATE 2 1 c", 
                                        "UPDATE 2 2 d", 
                                        "MERGE 1 1 1 2",
                                        "MERGE 2 2 2 1", 
                                        "MERGE 2 1 1 1", 
                                        "PRINT 1 1", 
                                        "UNMERGE 2 2", 
                                        "PRINT 1 1"} };

    vector<vector<string>> vd = { {"EMPTY", "group"},{"d", "EMPTY"} };

    for (int i = 0; i < vv.size(); i++)
    {
        vector<string> t = solution(vv[i]);

        bool flag = false;
        for (int j = 0; j < t.size(); j++)
        {
            if (vd[i][j] != t[j])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << " error " << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
     

}