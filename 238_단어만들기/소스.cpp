#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool flag = false;

    //True when even one word has been changed
    vector<bool> changed_word(words.size(), false);

    //To indicate the number of times a string has been replaced.
    queue<pair<string, int>> StrIn_Qpair;

    //Verify that the target string is in the vector
    for (int i = 0; i < words.size(); i++) {
        if (target == words[i]) {
            flag = true;
            break;
        }
    }

    //When the string is in the vector
    if (flag) {
        StrIn_Qpair.push(make_pair(begin, 0));

        while (!StrIn_Qpair.empty()) {
            //cout <<"size? = " << StrIn_Qpair.size() << endl;
            string temp_begin = StrIn_Qpair.front().first;
            int replace_count = StrIn_Qpair.front().second;
            StrIn_Qpair.pop();

            //When matching the string you are looking for
            if (temp_begin == target) {
                answer = replace_count;
                break;
            }


            for (int i = 0; i < words.size(); i++) {
                //If it's a string that's changed at least once,
                if (changed_word[i] == true) {
                    continue;
                }

                //If there is only one character difference between the string you currently have and the string you want to replace.
                //and not changed at least once
                else {
                    int string_diff_count = 0;

                    for (int j = 0; j < words[i][j]; j++) {
                        if (temp_begin[j] != words[i][j]) {
                            string_diff_count++;
                        }
                    }

                    //push if only one difference occurs
                    if (string_diff_count == 1) {
                        changed_word[i] = true;
                        StrIn_Qpair.push(make_pair(words[i], replace_count + 1));
                    }
                }
            }
        }
    }
    //When the string is not in the vector
    else {
        return answer;
    }
    return answer;
}
int main() {
    string be = "hit";
    string tart = "cog";
    vector<string> v = { "hot","dot","dog","lot","log","cog" };
    cout << "solution ? " << solution(be, tart, v) << endl;
    cout << endl;
}