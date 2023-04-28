#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) 
{
    int answer = 0;

    for (int x = i; x <= j; x++)
    {
        string temp = to_string(x);
        for (int y = 0; y < temp.size(); y++)
        {
            int xy = temp[y] - '0';
            if (xy == k)
            {
                answer++;
            }
        }
    }


    return answer;
}

int main()
{
    solution(1, 13, 1);
}