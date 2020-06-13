#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int count = 0;
    int max = 501;
    while (max > 0) {
        max--;

        if (num == 1) {
            answer = count;
            break;
        }

        else if (max == 0) {
            answer = -1;
            break;
        }


        if (num % 2 == 0) {
            num = num / 2;
            count++;
        }
        else if (num % 2 == 1) {
            num = num * 3 + 1;
            count++;
        }

    }

    return answer;
}