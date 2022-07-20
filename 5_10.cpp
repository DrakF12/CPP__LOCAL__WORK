// 请根据输入两个字符串，求它们的最长公共子串，输出最长公共子串的长度。
// 其他情况：找不到子串则输出0
// 例如：
// 输入：abcabcddd abcabc 最长公共子串为abcabc，输出其长度6
// 输入：abc1edf abcedf 最长公共子串有abc和def两个，输出其长度3
// 华为招聘公众号
#include <iostream>
using namespace std;
#include <string>
#include <vector>
int main()
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (str1[0] == str2[0])
        dp[0][0] = 1;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (str1[i] == str2[0])
        {
            dp[i][0] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str2[i] == str1[0])
        {
            dp[0][i] = 1;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == ans && i - ans + 1 >= 0)
            {
                cout << str1.substr(i - ans + 1, ans) << endl;
            }
        }
    }
    getchar();
    getchar();
    return 0;
}