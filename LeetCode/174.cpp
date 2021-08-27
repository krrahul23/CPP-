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
    int dp[205][205];
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        memset(dp, -1, sizeof(dp));
        return recur(0, 0, dungeon.size(), dungeon[0].size(), dungeon);
    }

    long recur(int i, int j, int n, int m, vector<vector<int>> &d)
    {
        if (i >= n || j >= m)
        {
            return INT_MAX;
        }

        if (i == n - 1 && j == m - 1)
        {
            return d[i][j] <= 0 ? abs(d[i][j]) + 1 : 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int op1 = recur(i + 1, j, n, m, d);
        int op2 = recur(i, j + 1, n, m, d);

        int minHealthRequired = min(op1, op2) - d[i][j];
        return dp[i][j] = (minHealthRequired <= 0) ? 1 : minHealthRequired;
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
