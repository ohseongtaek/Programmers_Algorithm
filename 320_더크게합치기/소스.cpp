#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;

    string t1 = "";
    string t2 = "";

    t1 = to_string(a) + to_string(b);
    t2 = to_string(b) + to_string(a);

    int tt1 = stoi(t1);
    int tt2 = stoi(t2);

    if (tt1 >= tt2)
    {
        answer =tt1;
    }
    else
    {
        answer = tt2;
    }



    return answer;
}