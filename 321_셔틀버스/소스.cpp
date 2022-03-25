#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define BUS_START 540

void strtimetable_to_inttimetable(vector<string> &timetalbe, vector<int> &tt)
{
    for (int i = 0; i < timetalbe.size(); i++)
    {
        int hour = stoi(timetalbe[i].substr(0, 2));
        int min = stoi(timetalbe[i].substr(3, 2));
        
        tt.push_back((hour * 60) + min);
    }
}

string int_dest_time_to_str_dest_time(int Dest_time)
{
    string answer = "";
    int hour = Dest_time / 60;
    int min = Dest_time % 60;

    if (hour < 10)
    {
        if (hour == 0)
        {
            answer = answer + "00:";
        }
        else
        {
            answer = answer + "0" + to_string(hour) + ":";
        }
    }
    else
    {
        answer = answer + to_string(hour) + ":";
    }

    if (min < 10)
    {
        if (min == 0)
        {
            answer = answer + "00";
        }
        else
        {
            answer = answer + "0" + to_string(min);
        }
    }
    else
    {
        answer = answer + to_string(min);
    }
    return answer;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> tt;
    
    strtimetable_to_inttimetable(timetable, tt);
    sort(tt.begin(), tt.end());

    int bus_time = BUS_START;
    int tt_Idx = 0;
    int Dest_time;

    // 버스 오는 횟수만큼 반복 
    for (int i = 1; i <= n; i++)
    {
        int Cnt = 0;

        // 크루원만큼 반복 
        for (int j = tt_Idx; j < tt.size(); j++)
        {
            // 버스보다 이전에 온 경우 즉 타는 경우 
            if (tt[j] <= bus_time)
            {
                tt_Idx++;
                Cnt++;
                // 승객이 최대인 경우 그만 태우고 탈출 
                if (Cnt == m)
                {
                    break;
                }
            }
        }

        // 마지막 버스인 경우 
        if (i == n)
        {
            // 마지막 버스에 자리가 없는경우 마지막 시간에서 -1 한 만큼 빨리오면 탈수있음 
            if (Cnt == m)
            {
                Dest_time = tt[tt_Idx - 1] - 1;
            }
            // 마지막 버스에 자리가 있는경우 그냥 타면 됨 
            else
            {
                Dest_time = bus_time;
            }
        }

        // 버스 시간 간격만큼 계속 늘려주기 
        bus_time = bus_time + t;
    }
    
    answer = int_dest_time_to_str_dest_time(Dest_time);
    return answer;
}

int main()
{
    vector<int> n = { 1,2,2,1,1,10 };
    vector<int> t = { 1,10,1,1,1,60 };
    vector<int> m = { 5,2,2,2,5,1,45 };
    vector<vector<string>> tb = { {"08:00", "08:01", "08:02", "08:03"},
                                  {"09:10", "09:09", "08:00"},
                                  {"09:00", "09:00", "09:00", "09:00"} ,
                                  {"00:01", "00:01", "00:01", "00:01", "00:01"} ,{"23:59"} ,
                                  {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"} };
    vector<string> dab = { "09:00",
                           "09:09",
                           "08:59",
                           "00:00",
                           "09:00",
                           "18:00" };
    for (int i = 0; i < n.size(); i++)
    {
        string ans = solution(n[i], t[i], m[i], tb[i]);
        if (ans == dab[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error = " << i << endl;
        }
    }
}