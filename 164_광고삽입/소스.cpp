#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 최대 시간 99시간 59분 59초 => 초로 변환 359999
#define TIME_MAX 360000

typedef long long ll;

int strTimeConvert(string strTime)
{
    int hour = stoi(strTime.substr(0, 2)) * 3600;
    int min = stoi(strTime.substr(3, 2)) * 60;
    int sec = stoi(strTime.substr(6, 2));

    return hour + min + sec;
}

string nTimeConvert(int ntime)
{
    string strRtn = "";
    
    ntime = ntime - 1;

    int hour = ntime / 3600;
    int min = (ntime % 3600) / 60;
    int sec = (ntime % 3600) % 60;

    if (hour <= 9)
    {
        strRtn += "0";
    }
    strRtn += to_string(hour);
    strRtn += ":";

    if (min <= 9)
    {
        strRtn += "0";
    }
    strRtn += to_string(min);
    strRtn += ":";
    
    if (sec <= 9)
    {
        strRtn += "0";
    }
    strRtn += to_string(sec);
    
    return strRtn;
}

string solution(string play_time, string adv_time, vector<string> logs) 
{
    string answer = "";
    
    // 전체 초 시간을 0으로 초기화 
    vector<int> ALL_Play_Time(TIME_MAX, 0);

    // Convert
    int nPtime = strTimeConvert(play_time);
    int nADtime = strTimeConvert(adv_time);

    // 마지막 광고 재생시간은 전체 시간 에서 광고시간을빼고 +1(실제 재생 시간)을 한 시점이다.
    int Last_ad_time = nPtime - nADtime + 1;

    // 최종 시간 
    int Good_time = 1;

    // 광고 재생 시간과 최댓값을 구하기 위한 변수 
    ll AD_play_time = 0;
    ll MAX_play_time = 0;

    // 플레이 타임에 대한 것 
    // 예외 : 동영상 재생시간 = 재생이 종료된 시각 - 재생이 시작된 시각(예를 들어, 00시 00분 01초부터 00시 00분 10초까지 동영상이 재생되었다면, 동영상 재생시간은 9초 입니다.)
    for (int i = 0; i < logs.size(); i++)
    {
        int start_time = strTimeConvert(logs[i].substr(0, 8));
        int end_time = strTimeConvert(logs[i].substr(9, 8));

        // 초 단위로 하나씩 늘려준다 !
        for (int j = start_time + 1; j <= end_time; j++)
        {
            ALL_Play_Time[j]++;
        }
    }

    // 가장 처음 재생할수있는 1초에 재생을 하고 누적된 재생시간을 하나씩 더함
    // 광고 재생 시간 과 최댓값을 저장함 
    for (int i = 1; i <= nADtime; i++)
    {
        AD_play_time += ALL_Play_Time[i];
        MAX_play_time += ALL_Play_Time[i];
    }

    // 위에서 저장한 1초에 시작한 광고재생시간과 최댓값을 아래 반복문에서 비교함
    for (int i = 2; i <= Last_ad_time; i++)
    {
        // 2초부터 시간은 마지막 시간에 1초를 더한 이후에 1초시간대를 빼주는것과 동일함
        AD_play_time += ll(ALL_Play_Time[i + nADtime - 1] - (ALL_Play_Time[i - 1]));
        if (AD_play_time > MAX_play_time)
        {
            MAX_play_time = AD_play_time;
            // 최종 광고 재생 시작 시간을 넣음 
            Good_time = i;
        }
    }

    answer = nTimeConvert(Good_time);

    return answer;
}

int main()
{
    vector<string> p = { "02:03:55","99:59:59","50:00:00" };
    vector<string> a = { "00:14:15","25:00:00","50:00:00" };
    vector<vector<string>> v = { {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"} ,
                                 {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"},
                                 {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"} };

    vector<string> answer = { "01:30:59","01:00:00","00:00:00" };

    for (int i = 0; i < p.size(); i++)
    {
        string result = solution(p[i], a[i], v[i]);
        if (result == answer[i])
        {
            cout << " good " << endl;
        }
        else
        {
            cout << " error " << endl;
            cout << result << " " << answer[i] << endl;
        }
    }

    return 0;
}                       