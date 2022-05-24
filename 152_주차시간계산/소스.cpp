#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

int TimeCal(string input, string output)
{
    int input_hour = stoi(input.substr(0, 2)) * 60;
    int input_minute = stoi(input.substr(3, 2));
    int output_hour = stoi(output.substr(0, 2)) * 60;
    int output_minute = stoi(output.substr(3, 2));

    return (output_hour + output_minute) - (input_hour + input_minute);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;
    map<string, vector<string>>::iterator iter;
    
    for (int i = 0; i < records.size(); i++)
    {
        string str_record = records[i];
        string time, number, direction;
        int count = 0;

        char* tok = strtok((char*)str_record.c_str(), " ");

        while (tok != NULL)
        {
            if (count == 0)
            {
                time = tok;
            }
            else if (count == 1)
            {
                number = tok;
            }
            else if (count == 2)
            {
                direction = tok;
            }
            count++;
            tok = strtok(NULL, " ");
        }
        m[number].push_back(time);
    }

    for (iter = m.begin(); iter != m.end(); iter++)
    {
        int time_sum = 0;
        int Money = 0;
        int AddMoney = 0;
        int DefaultMoney = fees[1];
        if (iter->second.size() % 2 != 0)
        {
            iter->second.push_back("23:59");
        }

        
        for (int i = 0; i < iter->second.size() - 1; i+=2)
        {
            time_sum += TimeCal(iter->second[i], iter->second[i + 1]);
        }

        cout << time_sum << " ";
        if (time_sum < fees[0])
        {
            Money = DefaultMoney;
        }
        else
        {
            //기본요금 
            time_sum = time_sum - fees[0];
            Money += DefaultMoney;
            
            // 추가요금 
            AddMoney = ceil(((double)time_sum / (double)fees[2])) * fees[3];
            Money += AddMoney;
        }
         
        answer.push_back(Money);
    }
    
    return answer;
}

int main()
{
                    // 기본시간 , 기본요금 , 추가시간, 추가요금 
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    vector<int> dab = solution(fees, records);
    for (int i = 0; i < dab.size(); i++)
    {
        cout << dab[i] << endl;
    }
}