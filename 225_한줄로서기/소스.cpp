#include <iostream>
using namespace std;

#define MAX 10

int result[MAX];

int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {

        int left;
        cin >> left;

        for (int j = 0; j < N; j++) {
            if (left == 0 && result[j] == 0) {      //not use and position ok
                result[j] = i + 1;
                break;
            }
            else if (result[j] == 0) {            //not use 
                left--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}