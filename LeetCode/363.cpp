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
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        int sum[m][n], mx = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto x = matrix[i][j];
                if (i > 0 && j > 0)
                    x = x + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                else if (i > 0 && j <= 0)
                    x = x + sum[i - 1][j];
                else if (i <= 0 && j > 0)
                    x = x + sum[i][j - 1];
                sum[i][j] = x;
                for (int r = 0; r <= i; r++)
                {
                    for (int c = 0; c <= j; c++)
                    {
                        auto chk = sum[i][j];
                        if (r > 0 && c > 0)
                            chk = chk - sum[r - 1][j] - sum[i][c - 1] + sum[r - 1][c - 1];
                        else if (r > 0 && c <= 0)
                            chk = chk - sum[r - 1][j];
                        else if (r <= 0 && c > 0)
                            chk = chk - sum[i][c - 1];
                        if (chk <= k)
                            mx = max(mx, chk);
                    }
                }
            }
        }
        return mx;
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
