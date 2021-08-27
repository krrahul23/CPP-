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
    int X[4] = {-1, 1, 0, 0};
    int Y[4] = {0, 0, -1, 1};
    int m, n, s;

    bool isSafe(vector<vector<char>> &board, int x, int y, int k)
    {
        return (x >= 0 && y >= 0 && x < m && y < n && k + 1 < s && board[x][y] != '*');
    }
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k)
    {
        if (board[i][j] != word[k])
            return false;
        if (k == s - 1)
            return true;
        char curr = board[i][j];
        board[i][j] = '*';
        bool success = false;

        for (int p = 0; p < 4; p++)
        {
            int x = i + X[p];
            int y = j + Y[p];
            if (isSafe(board, x, y, k))
            {
                success = (success || dfs(board, word, x, y, k + 1));
            }
        }
        board[i][j] = curr; // Backtrack
        return success;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        if (m == 0)
            return false;
        n = board[0].size();
        s = word.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
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
