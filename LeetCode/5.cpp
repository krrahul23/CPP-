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
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int start = 0, end = 0;
        int ans = 1;
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int gap = 1; gap < n; gap++)
        {
            for (int i = 0; i < n - gap; i++)
            {
                if (gap == 1)
                {
                    if (s[i] == s[i + 1])
                    {
                        dp[i][i + 1] = 1;
                        dp[i + 1][i] = 1;
                        start = i, end = i + 1, ans = 2;
                    }
                }
                int j = gap + i;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                    if (j - i + 1 > ans)
                        ans = j - i + 1, start = i, end = j;
                }
                else
                    dp[i][j] = 0;
            }
        }
        rep(i, n)
        {
            rep(j, n) cout << dp[i][j] << " ";
            cout << endl;
        }

        return s.substr(start, end - start + 1);
    }
};

void solve()
{
    Solution a = Solution();
    string ans = a.longestPalindrome("bccd");
    cout << ans << endl;
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
