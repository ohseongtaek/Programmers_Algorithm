#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> numbers) 
{
    sort(numbers.begin(), numbers.end()); // 오름차순 정렬
    int n = numbers.size();
    int max_product = numbers[n - 1] * numbers[n - 2]; // 가장 큰 두 수의 곱
    int min_product = numbers[0] * numbers[1]; // 가장 작은 두 수의 곱
    return max(max_product, min_product);
}

int main()
{
    solution({ 1, 2, -3, 4, -5 });
}