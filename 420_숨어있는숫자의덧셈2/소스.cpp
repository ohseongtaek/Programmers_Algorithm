#include <string>
#include <vector>

using namespace std;

int solution(string my_string)
{
    int sum = 0;
    bool found_number = false;
    int number = 0;

    for (char c : my_string) 
    {
        if (isdigit(c)) 
        {
            found_number = true;
            number *= 10;
            number += (c - '0');
        }
        else 
        {
            if (found_number) 
            {
                sum += number;
                number = 0;
                found_number = false;
            }
        }
    }

    if (found_number) 
    {
        sum += number;
    }

    return sum;
}

int main()
{
    solution("a10b");
}