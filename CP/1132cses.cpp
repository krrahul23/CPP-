#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 2e5 + 5;
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

int n;
vector<int> g[MAX_N], ans(MAX_N, -1);

int bfs(int s)
{
    int u;
    queue<int> Q;
    vector<int> d(n + 1, -1);
    d[s] = 0;
    ans[s] = max(ans[s], d[s]);
    Q.push(s);

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for (int v : g[u])
        {
            if (d[v] == -1)
            {
                Q.push(v);
                d[v] = d[u] + 1;
                ans[v] = max(ans[v], d[v]);
            }
        }
    }
    return u;
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int Diam_end_1 = bfs(1);
    int Diam_end_2 = bfs(Diam_end_1);
    bfs(Diam_end_2);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
