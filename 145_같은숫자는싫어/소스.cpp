#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        //cout << "what i? =" << i << endl;
        if (i == 0) {
            // cout << "good1" << endl;
            answer.push_back(arr[0]);
        }
        else {
            if (arr[i - 1] == arr[i]) {
                // cout << "good2" << endl;
                continue;
            }
            else {
                // cout << "good3" << endl;
                answer.push_back(arr[i]);
            }
        }
        //  for (int j = 0; j < answer.size(); j++) {
        //      cout << answer[j] << endl;
        //  }
    }
    return answer;
}