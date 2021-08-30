#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const double eps = 1e-9;
//#define int long long
#define endl "\n"
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define tr(it, a) for (auto it = a.begin(); i != a.end(); it++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

class Solution
{
public:
    queue<pair<pair<int, int>, int>> q;

    void dfs(vector<vector<int>> &grid, int x, int y, int row, int col, vector<vector<bool>> &vis)
    {
        if (x < 0 || x >= row || y < 0 || y >= col || vis[x][y] || grid[x][y] == 0)
            return;
        vis[x][y] = true;
        grid[x][y] = 0;
        q.push({{x, y}, 0});

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 < 0 || x1 >= row || y1 < 0 || y1 >= col || vis[x1][y1] || grid[x1][y1] == 0)
                continue;
            dfs(grid, x1, y1, row, col, vis);
        }
        return;
    }

    int shortestBridge(vector<vector<int>> &grid)
    {

        int row = grid.size();
        int col = grid[0].size();
        bool flag = false;

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    dfs(grid, i, j, row, col, vis);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if (x1 < 0 || x1 >= row || y1 < 0 || y1 >= col || vis[x1][y1])
                    continue;

                if (grid[x1][y1] == 1)
                    return dis;
                else
                {
                    vis[x1][y1] = true;
                    q.push({{x1, y1}, dis + 1});
                }
            }
        }
        return -1;
    }
};

void solve()
{
}
int32_t main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
