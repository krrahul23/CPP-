#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const double eps = 1e-9;
#define int long long
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
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
ll qexp(ll a, ll b, ll m)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int bytes;
    cin >> bytes;
    vector<int> v(n);
    map<int, pair<int, int>> p;
    set<int> s;
    rep(i, n)
    {
        int key;
        cin >> key;
        v[i] = key;
        s.insert(key);
    }
    sort(v.begin(), v.end());
    rep(i, n)
    {
        int temp = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
        p[v[i]].first = temp;
        temp = v.end() - upper_bound(v.begin(), v.end(), v[i]);
        p[v[i]].second = temp;
    }
    int ans = INT_MAX;
    auto it = s.begin();
    int temp = (bytes * 8) / n;
    temp = qexp(2, temp, MOD);
    // temp = (ll)1 << temp;
    // cout << temp << endl;
    if (temp >= s.size())
        cout << 0 << endl;

    else
    {
        auto it = s.begin();
        while (temp - 1)
        {
            it = next(it);
            temp--;
        }
        for (auto i = s.begin(); it != s.end();)
        {
            ans = min(ans, p[*i].first + p[*it].second);
            it++;
            i++;
        }
        cout << ans << endl;
    }
}
int32_t main()
{
    fast
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
