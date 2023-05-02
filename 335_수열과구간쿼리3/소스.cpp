#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) 
{
    vector<int> answer;

    for (int i = 0; i < queries.size(); i++)
    {
        int one = queries[i][0];
        int two = queries[i][1];

        int temp = arr[one];
        arr[one] = arr[two];
        arr[two] = temp;
    }

    answer = arr;

    return answer;
}