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

public:
    void dfs(vector<vector<char>> &board, pair<int, int> p)
    {
        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, -1, 1};

        int x = p.first, y = p.second;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size())
                continue;
            if (!visited[a][b] && board[a][b] == 'O')
                dfs(board, {a, b});
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        visited = vector<vector<bool>>(n + 3, vector<bool>(m + 3));
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O' && !visited[0][i])
                dfs(board, {0, i});
            if (board[n - 1][i] == 'O' && !visited[n - 1][i])
                dfs(board, {n - 1, i});
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(board, {i, 0});
            if (board[i][m - 1] == 'O' && !visited[i][m - 1])
                dfs(board, {i, m - 1});
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
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
