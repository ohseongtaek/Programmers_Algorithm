#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<int> v;
    int cnt = 1;
    bool check = false;
    string numstr = "";
    while (true) 
    {
        check = false;
        if (answer % 3 == 0) 
        {
            answer++;
            continue;
        }
        numstr = to_string(answer);

        if (numstr.find("3") != string::npos) 
        {
            answer++;
            check = true;
        }

        if (check)
        {
            continue;
        }

        if (cnt == n)
        {
            break;
        }
        answer++;
        cnt++;
    }
    return answer;

    return answer;
}

int main()
{
    solution(15);
}