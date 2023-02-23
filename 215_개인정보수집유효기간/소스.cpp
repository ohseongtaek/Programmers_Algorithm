#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;

    map<char, int> cim;
    vector<int> v;

    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int baseline = (year * 12 * 28) + (month - 1) * 28 + day;

    for (int i = 0; i < terms.size(); i++)
    {
        stringstream ss(terms[i]);
        char lank;
        int t_month;

        ss >> lank >> t_month;

        cim[lank] = t_month;
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        int ty = stoi(privacies[i].substr(0, 4));
        int tm = stoi(privacies[i].substr(5, 2));
        int td = stoi(privacies[i].substr(8, 2));

        char a = privacies[i].back();

        int temp = (ty * 12 * 28) + (tm - 1) * 28 + td + (cim[a] * 28 - 1);

        v.push_back(temp);
    }


    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < baseline)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;

    /*
    today.erase(4,1);
    today.erase(6,1);

    vector<pair<long long, string>> vpterm;

    long long lltoday = stoll(today);

    for (int i = 0; i < terms.size(); i++)
    {
        string temp = terms[i];
        string lank = temp.substr(0, 1);
        long long month = stoll(temp.substr(2, temp.size() - 2));
        month = month * 100;

        vpterm.push_back(make_pair(month, lank));
    }


    for (int i = 0; i < privacies.size(); i++)
    {
        string lank = privacies[i].substr(privacies[i].size() - 1);
        privacies[i].erase(10);
        privacies[i].erase(4, 1);
        privacies[i].erase(6, 1);

        // 일자를 계산하고 한개를 줄여줌 그리고 0인경우 month에서 뺌 또 month 가 0이면 year 에서 한개 빼줌 
        long long dayLimit = stoll(privacies[i].substr(privacies[i].size() - 2));
        long long month = stoll(privacies[i].substr(privacies[i].size() - 4, 2));
        long long year = stoll(privacies[i].substr(privacies[i].size() - 8, 4));
        
        dayLimit--;
        
        if (dayLimit <= 0)
        {
            month--;
            if (month <= 0 || month >= 13)
            {
                year--;
                month = 12;
            }

            dayLimit = 28;
        }

        char mon[3] = { 0, };
        char day[3] = { 0, };

        sprintf(mon, "%02d", (int)month);
        sprintf(day, "%02d", (int)dayLimit);

        string result = to_string(year) + mon + day;

        long long one = 0;
        for (int j = 0; j < vpterm.size(); j++)
        {
            if (lank == vpterm[j].second)
            {
                one = stoll(result);
                one += vpterm[j].first;
                break;
            }
        }

        // 달 예외처리 
        string one2 = to_string(one);
        long long month2 = stoll(one2.substr(one2.size() - 4, 2));
        long long year2 = stoll(one2.substr(one2.size() - 8, 4));
        long long dayLimit2 = stoll(one2.substr(one2.size() - 2));

        while (month2 > 12)
        {
            year2++;
            month2 -= 12;
        }

        char mon2[3] = { 0, };
        char day2[3] = { 0, };

        sprintf(mon2, "%02d", (int)month2);
        sprintf(day2, "%02d", (int)dayLimit2);

        string result2 = to_string(year2) + mon2 + day2;

        if (stoll(result2) < stoll(today))
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
    */
}

int main()
{

    vector<string> today = { "2022.05.19", "2020.01.01", "2024.06.08", "2022.02.28" };
    vector<vector<string>> terms = { {"A 6", "B 12", "C 3"}, {"Z 3", "D 5"}, {"A 18"}, {"A 23"} };
    vector<vector<string>> privacies = { {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"} ,
                                         {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"},
                                         {"2022.06.08 A"},
                                         {"2020.01.28 A"} };


    vector<vector<int>> answer = { {1, 3} , {1, 4, 5}, {1}, {1} };

    for (int i = 0; i < today.size(); i++)
    {
        vector<int> dab = solution(today[i], terms[i], privacies[i]);

        bool flag = false;
        for (int j = 0; j < dab.size(); j++)
        {
            if (dab[j] != answer[i][j])
            {
                flag = true;
            }
        }

        if (flag == true)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << " good " << endl;
        }
    }
}


/*
고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있습니다. 
약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다. 
당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다. 
수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.

예를 들어, 
A라는 약관의 유효기간이 12 달이고, 2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면 해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.

당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.

모든 달은 28일까지 있다고 가정합니다.

다음은 오늘 날짜가 2022.05.19일 때의 예시입니다.

약관 종류	유효기간
A	6 달
B	12 달
C	3 달
번호	개인정보 수집 일자	약관 종류
1	2021.05.02	A
2	2021.07.01	B
3	2022.02.19	C
4	2022.02.20	C
첫 번째 개인정보는 A약관에 의해 2021년 11월 1일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
두 번째 개인정보는 B약관에 의해 2022년 6월 28일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
세 번째 개인정보는 C약관에 의해 2022년 5월 18일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
네 번째 개인정보는 C약관에 의해 2022년 5월 19일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
따라서 파기해야 할 개인정보 번호는 {1, 3}입니다.

오늘 날짜를 의미하는 문자열 today, 약관의 유효기간을 담은 1차원 문자열 배열 terms와 수집된 개인정보의 정보를 담은 1차원 문자열 배열 privacies가 매개변수로 주어집니다. 이때 파기해야 할 개인정보의 번호를 오름차순으로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

제한사항
today는 "YYYY.MM.DD" 형태로 오늘 날짜를 나타냅니다.
1 ≤ terms의 길이 ≤ 20
terms의 원소는 "약관 종류 유효기간" 형태의 약관 종류와 유효기간을 공백 하나로 구분한 문자열입니다.
약관 종류는 A~Z중 알파벳 대문자 하나이며, terms 배열에서 약관 종류는 중복되지 않습니다.
유효기간은 개인정보를 보관할 수 있는 달 수를 나타내는 정수이며, 1 이상 100 이하입니다.
1 ≤ privacies의 길이 ≤ 100
privacies{i}는 i+1번 개인정보의 수집 일자와 약관 종류를 나타냅니다.
privacies의 원소는 "날짜 약관 종류" 형태의 날짜와 약관 종류를 공백 하나로 구분한 문자열입니다.
날짜는 "YYYY.MM.DD" 형태의 개인정보가 수집된 날짜를 나타내며, today 이전의 날짜만 주어집니다.
privacies의 약관 종류는 항상 terms에 나타난 약관 종류만 주어집니다.
today와 privacies에 등장하는 날짜의 YYYY는 연도, MM은 월, DD는 일을 나타내며 점(.) 하나로 구분되어 있습니다.
2000 ≤ YYYY ≤ 2022
1 ≤ MM ≤ 12
MM이 한 자릿수인 경우 앞에 0이 붙습니다.
1 ≤ DD ≤ 28
DD가 한 자릿수인 경우 앞에 0이 붙습니다.
파기해야 할 개인정보가 하나 이상 존재하는 입력만 주어집니다.
입출력 예
today	terms	privacies	result
"2022.05.19"	{"A 6", "B 12", "C 3"}	{"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"}	{1, 3}
"2020.01.01"	{"Z 3", "D 5"}	{"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"}	{1, 4, 5}
입출력 예 설명
입출력 예 #1

문제 예시와 같습니다.
입출력 예 #2

약관 종류	유효기간
Z	3 달
D	5 달
번호	개인정보 수집 일자	약관 종류
1	2019.01.01	D
2	2019.11.15	Z
3	2019.08.02	D
4	2019.07.01	D
5	2018.12.28	Z
오늘 날짜는 2020년 1월 1일입니다.

첫 번째 개인정보는 D약관에 의해 2019년 5월 28일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
두 번째 개인정보는 Z약관에 의해 2020년 2월 14일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
세 번째 개인정보는 D약관에 의해 2020년 1월 1일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
네 번째 개인정보는 D약관에 의해 2019년 11월 28일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
다섯 번째 개인정보는 Z약관에 의해 2019년 3월 27일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
*/