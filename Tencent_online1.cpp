#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
    deque<int> dt{1, 3, 4, 2, 3, 1, 2, 2, 4, 2};
    for (int i = 0; i < dt.size(); i++)
        cout << dt[i] << " ";
    sort(dt.begin(), dt.end());
    cout << endl;
    for (int i = 0; i < dt.size(); i++)
        cout << dt[i] << " ";
    getchar();
    return 0;
}