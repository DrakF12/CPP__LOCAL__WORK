#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dirs = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
vector<vector<int>> stones = {{0, 1}, {-1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 0}, {0, -1}};

int dfs(vector<vector<char>> &nums, vector<vector<bool>> &ban, int x, int y, int step);
int ans = 0;
int main()
{
    int T = 0;
    cin >> T;
    int N = 0;
    int M = 0;
    int st_x, st_y, tar_x, tar_y;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        vector<vector<char>> nums(N, vector<char>(M, '1'));
        vector<vector<bool>> ban(N, vector<bool>(M, 0));
        string s;
        for (int j = 0; j < N; j++)
        {
            cin >> s;
            for (int k = 0; k < M; k++)
            {
                if (s[k] == 'K')
                {
                    st_x = j;
                    st_y = k;
                    nums[j][k] = 'K';
                }
                else if (s[k] == 'T')
                {
                    tar_x = j;
                    tar_y = k;
                    nums[j][k] = 'T';
                }
                else
                    nums[j][k] = s[k];
            }
        }
        int x = st_x;
        int y = st_y;
        ans = 10000;
        ban[x][y] = 1;
        dfs(nums, ban, x, y, 0);
        if (ans == 10000)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
int dfs(vector<vector<char>> &nums, vector<vector<bool>> &ban, int x, int y, int step)
{
    int M = nums[0].size();
    int N = nums.size();
    if (nums[x][y] == 'T')
    {
        ans = min(ans, step);
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        int next_x = x + dirs[i][0];
        int next_y = y + dirs[i][1];
        int stone_x = x + stones[i][0];
        int stone_y = y + stones[i][1];
        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && ban[next_x][next_y] == 0 && nums[stone_x][stone_y] != '0')
        {
            ban[next_x][next_y] = 1;
            dfs(nums, ban, next_x, next_y, step + 1);
            ban[next_x][next_y] = 0;
        }
    }
    return 0;
}