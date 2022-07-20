#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dt;
    while (n / 10 != 0)
    {
        dt.push_back(n % 10);
        n = n / 10;
    }
    dt.push_back(n);
    vector<int> begin_index;
    int len = 1;
    for (int i = 0; i < dt.size(); i++)
    {
        for (int bias = 1; i - bias >= 0 && i + bias < dt.size(); bias++)
        {
            if (dt[i - bias] != dt[i + bias])
            {
                int sub_len = 2 * bias - 1;
                int begin = i - bias + 1;
                if (sub_len > len)
                {
                    len = sub_len;
                    begin_index.clear();
                    begin_index.push_back(begin);
                }
                else if (sub_len == len)
                {
                    begin_index.push_back(begin);
                }
                break;
            }
        }
        if (i < dt.size() - 1 && dt[i] == dt[i + 1])
        {
            for (int bias = 1; i - bias >= 0 && i + 1 + bias < dt.size(); bias++)
            {
                if (dt[i - bias] != dt[i + 1 + bias])
                {
                    int sub_len = 2 * bias;
                    int begin = i - bias + 1;
                    if (sub_len > len)
                    {
                        len = sub_len;
                        begin_index.clear();
                        begin_index.push_back(begin);
                    }
                    else if (sub_len == len)
                    {
                        begin_index.push_back(begin);
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < begin_index.size(); i++)
    {
        int begin = begin_index[i];
        for (int j = 0; j < len; j++)
        {
            cout << dt[begin + j] << " ";
        }
        cout << endl;
    }
    getchar();
    getchar();
    return 0;
}