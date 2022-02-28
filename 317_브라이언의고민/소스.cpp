#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
문제의 조건에 의해, 삽입되는 기호는 총 26가지(알파벳 소문자의 수)이며 각각은 한 번씩만 적용될 수 있습니다. 
즉, 각 알파벳의 개수와 위치를 세면 어떤 단어에 어떤 규칙으로 적용되었는지 알 수 있습니다.

기호의 개수가 1개 혹은 3개 이상인 경우, 이 기호는 규칙 1에 의해 추가된 기호임을 알 수 있습니다. 
기호의 개수가 2개이면서 사이에 들어간 글자(대문자)의 수가 2개 이상인 경우, 이 기호는 규칙 2에 의해 추가된 기호임을 알 수 있습니다. 

기호의 개수가 2개이면서 사이에 들어간 글자의 수가 1개일 때는 규칙 1 혹은 규칙 2가 모두 적용될 수 있는데, 
이 경우에도 다음의 유일한 예외를 제외하고는 규칙 2가 적용된 기호로 간주할 수 있습니다. 
a A b B b C a 즉, 다른 기호의 구간 안에 있는 경우입니다.

즉, 각 기호 별로 개수를 세어, 
기호의 개수가 2개가 아닌 경우 규칙 1, 
2개인 경우 규칙 2(위에서 설명한 경우 제외)로 적용된 기호로 간주하고 
그에 맞게 규칙이 올바르게 적용되었는지를 판단하면 됩니다.
*/

string solution(string sentence) {
    string answer = "";
    const string invalid = "invalid";
    vector<string> words;
    vector<bool> checked(26);
    bool first_rule = false;
    bool second_rule = false;
    char char_rule1 = NULL;
    char char_rule2 = NULL;
    string word = "";

    for (int i = 0; i < sentence.length(); ++i) {
        // 규칙 1+2인 경우 
        if (first_rule && second_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];
                // 시작한 소문자로 끝을 봐야함 
                if (i + 1 == sentence.length())
                    return invalid;
                // 대문자가 연달아 나올수가 없음 
                else if (isupper(sentence[i + 1]))
                    return invalid;
                // 규칙 2의 특수문자로 끝나야함 
                else if (char_rule1 != sentence[i + 1] && char_rule2 != sentence[i + 1])
                    return invalid;
            }
            // 현재 문자가 소문자인경우 
            if (islower(sentence[i])) {
                // 현재 문자가 규칙2의 특수문자인경우 
                if (char_rule2 == sentence[i]) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;

                    second_rule = false;
                    checked[char_rule2 - 'a'] = true;
                    char_rule2 = NULL;

                    words.push_back(word);
                    word = "";

                    continue;
                }
                // 범위를 넘어가거나 다른 단어에 사용된 문자인경우 
                if (i + 1 == sentence.length())
                    return "invalid";
                else if (islower(sentence[i + 1]))
                    return "invalid";
            }
        }
        // 규칙 1인 경우 
        else if (first_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];
                // 단어가 끝난경우 
                if (i + 1 == sentence.length()) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
                // 단어가 끝나고 다음 문자가 대문자인경우 
                else if (isupper(sentence[i + 1])) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
                // 단어가 끝나고 다음문자가 소문자인데 현재 사용하는 특수문자 규칙이 아닌경우 
                else if (char_rule1 != sentence[i + 1]) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
            }
            // 규칙에 어긋난경우 
            if (islower(sentence[i])) {
                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]))
                    return invalid;
            }
        }
        // 규칙2인 경우 
        else if (second_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];
                // 해당 소문자로 끝나야 하기 때문에 예외처리 
                if (i + 1 == sentence.length())
                    return invalid;
                // 다음 문자가 소문자이며, 규칙 2의 특수문자가 아닌 새로운 특수문자인경우 (규칙 1+2 인 경우)
                else if (islower(sentence[i + 1]) && char_rule2 != sentence[i + 1]) {
                    if (char_rule2 == sentence[i - 1]) {
                        if (checked[sentence[i + 1] - 'a'])
                            return invalid;
                        first_rule = true;
                        char_rule1 = sentence[i + 1];
                    }
                    else
                        return invalid;
                }
            }
            // 현재 문자가 소문자인경우 종료되는 루틴으로 벡터 추가 
            if (islower(sentence[i])) {
                second_rule = false;
                checked[char_rule2 - 'a'] = true;
                char_rule2 = NULL;
                words.push_back(word);
                word = "";
            }
        }
        // 새로운 단어의 시작인 경우 
        else {
            if (isupper(sentence[i])) {
                word += sentence[i];
                first_rule = true;

                // 마지막 문자인 경우 
                if (i + 1 == sentence.length()) {
                    first_rule = false;
                    words.push_back(word);
                    word = "";
                }

                // 규칙1이 끝난 이후 새로운 문자가 다시 규칙 1인 경우 
                else if (isupper(sentence[i + 1])) {
                    first_rule = false;
                    words.push_back(word);
                    word = "";
                }

                // 다음문자가 소문자라면 규칙에 의거 어디에 포함되는지 확인하는 로직 
                else if (islower(sentence[i + 1])) {
                    
                    // 이미 사용된 소문자인지 확인하기 
                    if (checked[sentence[i + 1] - 'a'])
                        return invalid;

                    char_rule1 = sentence[i + 1];

                    // 소문자가 몇번 나왔는지 확인하는 벡터 
                    vector<int> pos;
                    for (int j = i + 1; j < sentence.length(); ++j)
                        if (sentence[j] == char_rule1)
                            pos.push_back(j);

                    // 규칙 2인경우 aAAAa 1개의 값을 가지고 있음 
                    if (pos.size() == 1)
                        continue;
                    // 규칙 1인경우 3개 이상 
                    else if (pos.size() >= 3) {
                        bool flag = true;
                        for (int j = 1; j < pos.size(); ++j) {
                            // 인덱스 차이를 나타내는 조건문
                            if (pos[i + 1] - pos[i] != 2) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            continue;
                    }
                    // 규칙 2 OR 규칙1+2 인 경우 
                    else {
                        first_rule = false;
                        char_rule1 = NULL;
                        words.push_back(word);
                        word = "";
                    }
                }
            }
            if (islower(sentence[i])) {
                if (checked[sentence[i] - 'a'])
                    return invalid;
                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]))
                    return invalid;
                second_rule = true;
                char_rule2 = sentence[i];
            }
        }
    }

    for (int i = 0; i < words.size(); ++i)
    {
        answer += (words[i] + " ");
        //cout << answer << endl;
    }
        
    answer.pop_back();
    return answer;
}

int main()
{
    vector<string> sen = { "HaEaLaLaO bWORLDb" ,"SpIpGpOpNpG JqOqA" ,"AxAxAxA oBoBoB" };

    /*
    "HELLO WORLD"
    "SIGONG JOA"
    "invalid"
    */
    string dab = solution(sen[1]);
    cout << dab << endl;
       	
}