#include <iostream>
using namespace std;
#include <vector>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sub(int bx, int by, int ex, int ey, int val, int &minval, int &num, vector<vector<int>> &map);
int main()
{
    int m = 0;
    int n = 0;
    cin >> m;
    cin >> n;
    int beginx = 0;
    int beginy = 0;
    cin >> beginx;
    cin >> beginy;
    int endx = 0;
    int endy = 0;
    cin >> endx;
    cin >> endy;
    int num = 0;
    cin >> num;
    vector<vector<int>> map(m, vector<int>(n, 0));
    for (int i = 0; i < num; i++)
    {
        int x = 0;
        int y = 0;
        cin >> x;
        cin >> y;
        map[x][y] = 1;
    }
    int ans = 0;
    int minval = 100000;
    sub(beginx, beginy, endx, endy, 0, minval, ans, map);
    cout << ans << " " << minval;
    getchar();
    getchar();
    return 0;
}
int sub(int bx, int by, int ex, int ey, int val, int &minval, int &num, vector<vector<int>> &map)
{
    if (bx == ex && by == ey)
    {
        if (val < -minval)
        {
            minval = val;
            num = 1;
        }
        else if (val == minval)
            num++;
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = bx + dx[i];
        int ny = by + dy[i];
        // cout << nx << " " << ny << endl;
        if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size() && map[nx][ny] != 1)
        {
            if (val + 1 > minval)
                continue;
            map[nx][ny] = 1;
            sub(nx, ny, ex, ey, val + 1, minval, num, map);
            map[nx][ny] = 0;
        }
    }
    return 0;
}