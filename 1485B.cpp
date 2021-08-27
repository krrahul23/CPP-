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

void solve()
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> pre(n + 1), v(n), rem(n + 1);
    rep(i, n) cin >> v[i];
    for (int i = 1; i < n - 1; i++)
    {
        rem[i] = v[i + 1] - v[i - 1] - 2;
    }
    for (int i = 1; i < n; i++)
    {
        pre[i] = rem[i] + pre[i - 1];
    }
    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (l == r)
            cout << k - 1 << endl;
        else if (r - l == 1)
        {
            int ans = v[r] - 2;
            ans += (k - v[l] - 1);
            cout << ans << endl;
        }
        else
        {
            int ans = pre[r - 1] - pre[l];
            ans += (k - v[r - 1] - 1);
            ans += (v[l + 1] - 2);
            cout << ans << endl;
        }
    }
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
