#include <iostream>
using namespace std;
#include <map>
#include <vector>
map<int, int> mp;
int func(int val) // 0,非质数
{
    for (int i = 2; i < val; i++)
    {
        if (val % i == 0)
            return 0;
    }
    return 1;
}

int getNumber(vector<int> &a)
{
    // write code here
    int n = a.size();
    mp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        mp[i] = func(i);
    }
    // cout << "ok";
    auto buff = a;
    while (buff.size() != 1)
    {
        int len = buff.size();
        vector<int> temp;
        cout << endl;
        for (int i = 0; i < len; i++)
        {
            if (mp[i + 1] == 1)
            {
                temp.push_back(buff[i]);
                cout << buff[i] << " ";
            }
        }
        buff = temp;
        if (buff.size() == 1)
            break;
    }
    return buff[0];
}

int main()
{
    // vector<int> a = {3, 1, 1, 4, 5, 6};
    vector<int> a = {1, 2, 3, 4};
    cout << getNumber(a);
    getchar();
    return 0;
}