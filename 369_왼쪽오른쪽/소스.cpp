#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> str_list) 
{
    vector<string> result;
    bool found_l = false, found_r = false;
    int l_index = -1, r_index = -1;

    
    for (int i = 0; i < str_list.size(); i++) 
    {
        if (str_list[i] == "l") 
        {
            found_l = true;
            l_index = i;
            break;
        }
        else if (str_list[i] == "r") 
        {
            found_r = true;
            r_index = i;
            break;
        }
    }

    if (!found_l && !found_r) 
    {
        return result;
    }
    
    if (found_l) 
    {
        for (int i = 0; i < l_index; i++) 
        {
            result.push_back(str_list[i]);
        }
    }
    else if (found_r) 
    {
        for (int i = r_index + 1; i < str_list.size(); i++) 
        {
            result.push_back(str_list[i]);
        }
    }

    return result;
}

int main()
{
    solution({ "l" });
}