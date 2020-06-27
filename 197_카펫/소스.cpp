#include <string>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> yacsu(int hap_size) {
    vector<int> tt;
    for (int i = 1; i <= hap_size; i++) {
        if (hap_size % i == 0) {
            tt.push_back(i);
        }
    }

    return tt;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> temp;
    int BY_size = brown + yellow;

    temp = yacsu(BY_size);

    /*
        for(int i=0; i<temp.size(); i++){
            cout << temp[i] <<endl;
        }
    */

    for (int i = 0; i < temp.size(); i++) {
        int SL = temp[i];
        if (!(BY_size % SL)) {
            int GL = BY_size / SL;
            if (((SL - 2) * (GL - 2)) == yellow) {
                answer.push_back(GL);
                answer.push_back(SL);
                break;
            }
        }
    }
    /*
        if(temp.size() % 2 == 0){
            answer.push_back(temp[temp.size()/2]);
            answer.push_back(temp[temp.size()/2-1]);
        }
        else if(temp.size() % 2 !=0){
                answer.push_back(temp[temp.size()/2]);
                answer.push_back(temp[temp.size()/2]);
        }
    */
    return answer;
}