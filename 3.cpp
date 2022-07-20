#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> one;
    vector<int> two;
    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        cin >> temp;
        one.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        cin >> temp;
        two.push_back(temp);
    }
    vector<vector<bool>> all(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int x = one[i];
        int y = two[i];
        all[x][y] = true;
        all[y][x] = true;
    }
    vector<vector<int>> ask;
    int qs = 0;
    cin >> qs;
    for (int i = 0; i < qs; i++)
    {
        vector<int> temp;
        int x = 0;
        int y = 0;
        cin >> x;
        cin >> y;
        temp.push_back(x);
        temp.push_back(y);
        ask.push_back(temp);
    }
    for (int i = 0; i < qs; i++)
    {
        int x = ask[i][0];
        int y = ask[i][1];
        if (all[x][y])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}