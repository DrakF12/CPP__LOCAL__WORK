#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    string input;
    cin >> input;
    vector<long long> sum_attack(n, 0);
    vector<long long> sum_defence(n, 0);
    long long sum_a = 0;
    long long sum_d = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == '0')
            sum_a += i;
        else if (input[i] == '1')
            sum_d += i;
        sum_attack[i] = sum_a;
        sum_defence[i] = sum_d;
    }
    int begin = 0;
    int end = n - 1;
    int mid = (begin + end) / 2;
    int ans = 10000005;
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        int left = sum_attack[mid];
        int right = sum_d - sum_defence[mid];
        ans = min(ans, abs(right - left));
        if (right > left)
        {
            begin = mid + 1;
        }
        else if (right < left)
        {
            end = mid - 1;
        }
        else
        {
            cout << "0";
            return 0;
        }
    }
    cout << ans;
    getchar();
    getchar();
    return 0;
}