#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<vector<int>> dt{{-5, 7}, {8, -6}, {6, -3}, {2, 1}, {-8, -5}};
int main()
{
    int n = dt.size();
    set<int> all;
    all.insert(0);
    vector<int> dp(200000, 0);
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << "****" << dt[i][0] << "  " << dt[i][1] << endl;
        set<int> buff;
        set<vector<int>> dpbuff;
        for (auto j : all)
        {
            int g_next = j + dt[i][0];
            int f_next = dp[j + 100000] + dt[i][1];
            // cout << g_next << " " << f_next << endl;
            if (all.find(g_next) == all.end())
            {
                vector<int> temp{g_next + 100000, f_next};
                dpbuff.insert(temp);
                buff.insert(g_next);
            }
            else if (f_next > dp[g_next + 100000])
            {
                vector<int> temp{g_next + 100000, f_next};
                dpbuff.insert(temp);
            }
        }
        for (auto j : buff)
        {
            all.insert(j);
        }
        for (auto j : dpbuff)
        {
            dp[j[0]] = j[1];
        }
    }
    for (auto i : all)
    {
        if (i >= 0 && dp[i + 100000] >= 0)
            ans = max(ans, dp[i + 100000] + i);
    }
    cout << ans;
    getchar();
    return 0;
}