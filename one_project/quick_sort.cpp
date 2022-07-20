#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &dt, int begin, int end);
int main()
{
    vector<int> dt = {0, 3, 2, 4, 2, 4, 2, 4, 2, 1, 43, 1, 3};
    for (auto i : dt)
        cout << i << " ";
    cout << endl;
    sort(dt, 0, dt.size() - 1);
    for (auto i : dt)
        cout << i << " ";
    getchar();
    return 0;
}

void sort(vector<int> &dt, int p, int q)
{
    if (p >= q)
        return;
    int begin = p;
    int end = q;
    while (p < q)
    {
        while (p < q && dt[q] >= dt[begin])
            q--;
        while (p < q && dt[p] <= dt[begin])
            p++;
        swap(dt[p], dt[q]);
    }
    swap(dt[begin], dt[p]);
    sort(dt, begin, p - 1);
    sort(dt, p + 1, end);
    return;
}