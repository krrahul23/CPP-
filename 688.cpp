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
    int dx[8] = {-1, 1, -1, 1, 2, -2, 2, -2};
    int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};

    double t[26][26][101];

    double solve(int n, int k, int r, int c)
    {
        if (r < 0 || r >= n || c < 0 || c >= n)
            return 0.0;
        if (t[r][c][k] != 0.0)
            return t[r][c][k];
        if (k == 0)
            return 1.0;
        double ans = 0;
        for (int i = 0; i < 8; i++)
        {
            int rr = r + dx[i];
            int cc = c + dy[i];
            ans += solve(n, k - 1, rr, cc);
        }
        ans = ans / 8;
        return t[r][c][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column)
    {
        memset(t, 0.0, sizeof(t));
        return solve(n, k, row, column);
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
