#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;


// The reason I use the address is because I need to keep copying the values.
bool DFS(string first, vector<vector<string>>& tickets, vector<bool>& use, vector<string>& answer, vector<string>& temp, int count) {

    //debug code
    //cout << "first ? " << first << endl;
    temp.push_back(first);

    //Return if vector size equal count
    if (count == tickets.size()) {
        answer = temp;
        return true;
    }

    //below logic make to full temp vector
    for (int i = 0; i < tickets.size(); i++) {

        //if the conditions are right
        if (first == tickets[i][0] && use[i] == false) {

            //deemed to have entered
            use[i] = true;

            //Repeat Function of DFS
            bool bRtn = DFS(tickets[i][1], tickets, use, answer, temp, count + 1);

            //If you navigate through every path,
            if (bRtn) {
                return true;
            }

            //If you don't navigate through all paths
            else {
                use[i] = false;
            }

        }
    }
    //Remove elements in the vector if all paths are not navigated
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    //sorting tickets vector
    //Because it's alphabetical order.
    sort(tickets.begin(), tickets.end());

    /* debug code
    for(int i=0; i<tickets.size(); i++){
        cout << tickets[i][0] << " " << tickets[i][1] << endl;
    }
    */

    //using position vector
    vector<bool> use(tickets.size(), false);

    //using count vector
    vector<string> temp;

    //Depth-first search function
    DFS("ICN", tickets, use, answer, temp, 0);

    return answer;
}


int main() {

    vector<string> dab;
    vector<vector<string>> vp = { {"ICN", "A"}, {"A", "C"}, {"A", "D"}, {"D", "B"}, {"B","A"} };

    dab = solution(vp);

    for (int i = 0; i < dab.size(); i++) {
        cout << dab[i] << endl;
    }

    return 0;
}