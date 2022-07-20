#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
int main()
{
    string N;
    getline(cin, N);
    string edge;
    getline(cin, edge);
    vector<int> data;
    int temp = 0;
    for (int i = 0; i < edge.length(); ++i)
    {
        if (edge[i] != ' ')
        {
            temp = temp * 10 + edge[i] - '0';
        }
        else
        {
            data.push_back(temp);
            temp = 0;
        }
    }
    data.push_back(temp);
    sort(data.begin(), data.end());
    int n = data.size();
    int key = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        int p = 0;
        int q = i - 1;
        while (p < q)
        {
            if (data[p] * data[p] + data[q] * data[q] > data[i] * data[i])
            {
                q--;
            }
            else if (data[p] * data[p] + data[q] * data[q] < data[i] * data[i])
            {
                p++;
            }
            else
            {
                key++;
                while (data[--q] == data[q] && q > p)
                {
                }
                p++;
            }
        }
    }
    cout << key;
    return 0;
}