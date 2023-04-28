#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) 
{
    int answer = -1;
    string temp = A;
    
    for (int i = 0; i < A.size(); i++)
    {
        if (temp == B)
        {
            answer = i;
            break;
        }

        temp = temp[temp.size()-1] + temp;
        temp = temp.substr(0, temp.size()-1);
    }


    return answer;
}

int main()
{
    solution("hello", "ohell");
}