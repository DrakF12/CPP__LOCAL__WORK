#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int a[1500005];
int euler_phi(int x) //欧拉函数
{
    int n = x;
    int k = (int)sqrt(double(n) + 0.5);
    int m = n;
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
        {
            m = m / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        m = m / n * (n - 1);
    return m;
}
void phi_table() //打表，求出1500000中所有的数的欧拉函数值
{
    memset(a, 0, sizeof(a));
    a[1] = 1;
    for (int i = 2; i <= 1500000; i++)
        if (!a[i])
        {
            for (int j = i; j <= 1500000; j += i)
            {
                if (!a[j])
                    a[j] = j;
                a[j] = a[j] / i * (i - 1);
            }
        }
}
int main()
{
    int n;
    phi_table();
    while (cin >> n)
    {
        cout << euler_phi(n) << endl;
        cout << a[n] << endl;
    }
}