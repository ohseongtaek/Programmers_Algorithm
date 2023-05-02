#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> stk;

    for (int i = 0; i < arr.size(); i++)
    {
        if (stk.empty() == true)
        {
            stk.push_back(arr[i]);
        }
        else if (stk[stk.size() - 1] < arr[i])
        {
            stk.push_back(arr[i]);
        }
        else
        {
			int k = stk.size() - 1;
			if (stk[k] >= arr[i])
			{
				stk.pop_back();
				i--;
			}
        }
      
    }

    return stk;
}

int main()
{
    solution({ 1, 4, 2, 5, 3 });
}