#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;

    int sum = 0;
    int x2 = 1;
    for (int i = 0; i < num_list.size(); i++)
    {
        sum += num_list[i];
        x2 *= num_list[i];
    }

    sum = sum * sum;

    if (sum > x2)
    {
        answer = 1;
    }
    

    return answer;
}