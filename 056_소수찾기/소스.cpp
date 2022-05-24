#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool FindSoSu(int sosu) {
    if (sosu == 1) return false;
    if (sosu == 2) return true;

    for (int i = 2; i <= sqrt(sosu); i++) {                      // find unique sosu
        if (sosu % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());      // sort 011 -> 110
    vector<bool> SoSuvec(stoi(numbers) + 1);                    // prime size -> 111

    SoSuvec[0] = false;
    for (long long i = 1; i < SoSuvec.size(); i++) {            // 1~110 go function(FindSoSu) and SoSuvec[i] store
        SoSuvec[i] = FindSoSu(i);
    }

    sort(numbers.begin(), numbers.end());                       //re sort 011
    /*
    for(int i=0; i<numbers.size(); i++){                        //debug code
        cout <<"what"<<numbers[i] <<endl;
    }
    */
    set<int> sto;                                               // set -> tree

    do {
        for (int i = 0; i < numbers.size(); i++) {

            //string tmp = numbers.substr(0, i);                //debug code

            char* tmp = &numbers[i];
            //cout << "what tmp =?"<<tmp<<endl;                 //debug code

            if (SoSuvec[atoi(tmp)]) {
                //cout << "numbers =?" <<numbers<<endl;         //debug code
                sto.insert(atoi(tmp));                          //unique store
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end())); // arr circle
    answer = sto.size();
    return answer;
}