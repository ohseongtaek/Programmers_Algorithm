#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    int answer = 0;

    int temp = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        int k = num_list[i];
        if (k == 1)
        {
            continue;
        }
        while (true)
        {
            if (k % 2 == 0)
            {
                k = k / 2;
            }
            else if (k % 2 == 1)
            {
                k = k - 1;
                k = k / 2;
            }
            temp++;

            if (k == 1)
            {
                break;
            }
        }
    }
    
    answer = temp;

    return answer;
}

int main()
{
    solution({ 12, 4, 15, 1, 14 });
}