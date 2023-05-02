#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        char test = str[i];
        cout << test << endl;
    }

    return 0;
}