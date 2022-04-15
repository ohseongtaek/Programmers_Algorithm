#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

// Input 
// vector<string> enroll    => 판매원 이름 
// vector<string> referral  => 각 판매원을 다단계 조직에 참여시킨 다른 판매원의 이름을 담은 배열 (상위 개념)
// vector<string> seller    => 판매량 집계 데이터의 판매원 이름을 나열한 배열
// vector<int> amount       => 판매량 집계 데이터의 판매 수량을 나열한 배열 amount

// Output
// 판매원에게 배분된 이익금의 총합을 계산하여(정수형으로), 입력으로 주어진 enroll에 이름이 포함된 순서에 따라 나열하면 됩니다.

// Rule 
// 판매원이 판매한 수입의 10%가 초대한 사람에게 전달 => 재귀로 계속 윗사람에게 들어감
// 단, 수입이 1% 미만인 경우에는 모두 가짐 
// ex) 3단계가 있다고 할때 A->B->C
// C 판매금 20원 
// C 수익률 18원 , B 수익률 2원
// B 의 10%을 A에게 줘야하지만 나누면 1원 미만이라 모두 자기가 가짐 

// Exception 
// [1] 1 <= enroll.size() <= 10,000 (최상위 민호의 이름은 무조건 포함되어 있지 않음)
// [2] referral.size() == enroll.size() (최상위 즉 민호가 추천한 사람은 모두 "-" 로 표시되고 enroll 의 사람은 referral 의 사람이 가입시킨것임)
// [3] enroll 의 순서는 조직에 참여한 순서다 
// [4] 1 <= seller.size() <= 100,000
// [5] seller 에는 중복된 이름이 들어갈 수 있음 !
// [6] amount.size() == seller.size() 
// [7] 칫솔 1개는 무조건 100원 
// [8] 구성원들 이름 10글자 이내 알파벳 소문자로 구성 


#define PEN_MONEY 100

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> m_str_int;

    // 민호의 돈 초기화 
    m_str_int["-"] = 0;
    // 다른 사람들의 돈 초기화 
    for (int i = 0; i < enroll.size(); i++)
    {
        m_str_int[enroll[i]] = 0;
    }
    
    // 판매한 사람들이 목록만큼 for문
    for (int i = 0; i < seller.size(); i++)
    {
        string current_man = seller[i];
        int money = amount[i] * PEN_MONEY;
        int up_money = money / 10;

        // 판매자는 수익금의 10프로를 제외하고 모두 더해줌 
        m_str_int[current_man] += money - up_money;

        // 상위로 10% 수익금을 던졌을때 10원 미만 혹은 맨 위가 민호인 경우에를 찾음 
		bool find_minho = false;
        bool not_money = false;
		while (1)
		{
            for (int j = 0; j < enroll.size(); j++)
            {
                // 현재 판매자와 같은 경우 referral 이 추천한 경우로 referral 에게 수익금을 줌 
                if (current_man == enroll[j])
                {
                    string next_man = referral[j];
                    int next_money = up_money / 10;
                    if (next_money == 0)
                    {
                        m_str_int[next_man] += up_money;
                        not_money = true;
                    }
                    else
                    {
                        m_str_int[next_man] += up_money - (up_money / 10);
                    }

                    up_money = next_money;
                    current_man = next_man;
                    if (next_man == "-")
                    {
                        find_minho = true;
                        break;
                    }
                }
            }

            if (not_money == true || find_minho == true)
            {
                break;
            }
		}
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(m_str_int[enroll[i]]);
    }

    return answer;
}


int main()
{
    vector<vector<string>> en =  { {"john", "mary", "edward", "sam",    "emily", "jaimie", "tod",    "young"} ,  {"john", "mary", "edward", "sam",    "emily", "jaimie", "tod",    "young"} };
    vector<vector<string>> ref = { {"-",    "-",    "mary",   "edward", "mary",  "mary",   "jaimie", "edward"} , {"-",    "-",    "mary",   "edward", "mary",  "mary",   "jaimie", "edward"} };

    vector<vector<string>> sel = { {"young", "john", "tod", "emily", "mary"} , {"sam", "emily", "jaimie", "edward"} };
    vector<vector<int>> am =     { {    12,      4,     2,       5,     10} ,  {   2,       3,        5,        4} };

    vector<vector<int>> dab = { {360, 958, 108, 0, 450, 18, 180, 1080} , {0, 110, 378, 180, 270, 450, 0, 0} };
   
    for (int i = 0; i < en.size(); i++)
    {
        vector<int> answer = solution(en[i], ref[i], sel[i], am[i]);
        
        bool flag = true;

        if (answer.size() != dab[i].size())
        {
            cout << " Error = size is Diff " << endl;
            cout << "answer size = " << answer.size() << ", dab size = " << dab[i].size() << endl;
            cout << " answer array = ";
            for (int j = 0; j < answer.size(); j++)
            {
                cout << answer[j] << " ";
            }
            cout << endl;

            cout << " dab[i] array = ";
            for (int j = 0; j < dab[i].size(); j++)
            {
                cout << dab[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < answer.size(); j++)
            {
                if (dab[i][j] != answer[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                cout << "[" << i << "]" << " is good " << endl;
            }
            else
            {
                cout << " not compare " << endl;
                for (int j = 0; j < answer.size(); j++)
                {
                    cout << "answer = " << answer[j] << ", dab = " << dab[i][j] << endl;
                }
            }
        }
    }
}

