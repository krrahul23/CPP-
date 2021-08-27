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

const ll N = 2e5 + 3;
typedef pair<ll, ll> LL;

unordered_set<ll> s[N];
LL edge[N];
ll n, m, Q, lab[N], x, y, ans[N];

ll Find(ll u)
{
    if (lab[u] < 0)
        return u;
    return lab[u] = Find(lab[u]);
}

void Union(ll p, ll q, ll nTime)
{
    p = Find(p);
    q = Find(q);
    if (p == q)
        return;
    if (s[p].size() < s[q].size())
        swap(p, q);
    for (auto i : s[q])
    {
        if (s[p].find(i) != s[p].end() && ans[i] == -1)
            ans[i] = nTime;
        s[p].insert(i);
    }
    lab[p] += lab[q];
    lab[q] = p;
}
void solve()
{
    cin >> n >> m >> Q;
    memset(lab, -1, sizeof(lab));
    memset(ans, -1, sizeof(ans));
    for (ll i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[i] = {x, y};
    }
    for (ll i = 1; i <= Q; i++)
    {
        cin >> x >> y;
        s[x].insert(i);
        s[y].insert(i);
        if (x == y)
            ans[i] = 0;
    }
    for (ll i = 1; i <= m; i++)
    {
        x = edge[i].first;
        y = edge[i].second;
        Union(x, y, i); //cout<<ans[1]; return 0;
    }
    for (ll i = 1; i <= Q; i++)
        cout << ans[i] << "\n";
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
