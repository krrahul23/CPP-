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
private:
    vector<vector<bool>> visited;
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

public:
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        visited[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (!visited[x][y] && grid[x][y] == 0)
                dfs(x, y, grid);
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited = vector<vector<bool>>(n + 5, vector<bool>(m + 5));

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && grid[i][0] == 0)
                dfs(i, 0, grid);
            if (!visited[i][m - 1] && grid[i][m - 1] == 0)
                dfs(i, m - 1, grid);
        }

        for (int i = 0; i < m; i++)
        {
            if (!visited[0][i] && grid[0][i] == 0)
                dfs(0, i, grid);
            if (!visited[n - 1][i] && grid[n - 1][i] == 0)
                dfs(n - 1, i, grid);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
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
