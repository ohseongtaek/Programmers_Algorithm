#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) 
{
    vector<int> answer;
    if (direction == "right") 
    {
        answer.push_back(0);
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            answer.push_back(numbers[i]);
        }
        answer[0] = numbers[numbers.size() - 1];
    }
    else 
    {
        for (int i = 1; i <= numbers.size() - 1; i++) 
        {
            answer.push_back(numbers[i]);
        }
        answer.push_back(numbers[0]);
    }
    return answer;
}

int main()
{
    solution({ 4, 455, 6, 4, -1, 45, 6 }, "left");
}