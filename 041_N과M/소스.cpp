#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0 };
bool visited[MAX] = { 0 };
void dfs(int cnt)
{
   // cout << "CNT" << cnt<<endl;
    if (cnt == m)               // 0==2 false
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)            // n=4      4번 반복하는데 순서가 어떻게되는거지?
    {
        //cout << "i의값은?" << i << endl;
        if (!visited[i])                // 처음에 false로 설정해서 if문들어감 
        {                               // 이후 visitied[1] 을 true로 설정 
            visited[i] = true;          // 이후 arr[1]에 1을 넣는다 
            arr[cnt] = i;               // 다시 재귀함수 들어가면 cnt=1이 됨 따라서 다시 if문들어감 들어가서 return함 이유는 vistited가 true고 cnt과 m이 같지도않아서 
            //cout << arr[cnt] << "good" << endl;
            dfs(cnt + 1);               // 이후 다시 false 설정 
            visited[i] = false;         // i=2로 들어감  그렇게되면 arr[2] = 2 가 arr[3] = 3 arr[4] = 4 가 들어감 ? 존나어려움 ㄹㅇ;
        }
    }
    //cout << "forEnd" << endl;
}

int main() {
    cin >> n >> m;          // 4, 2 일경우 
    dfs(0);
}