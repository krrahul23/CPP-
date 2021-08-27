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

vector<int> adj[MAX_N], visited(MAX_N), odd(MAX_N);
int timer = 0;
vector<pair<int, int>> ans;
void dfs(int node, int parent)
{
    visited[node] = ++timer;
    for (auto i : adj[node])
    {
        if (i != parent)
        {
            if (!visited[i])
            {
                dfs(i, node);
                if (odd[i])
                {
                    odd[i] = 0;
                    ans.push_back({i, node});
                }
                else
                {
                    odd[node] ^= 1;
                    ans.push_back({node, i});
                }
            }
            if (visited[node] > visited[i])
            {
                odd[node] ^= 1;
                ans.push_back({node, i});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i, n) if (!visited[i])
        dfs(i, -1);
    int sum = accumulate(odd.begin(), odd.begin() + n + 1, 0);
    if (sum)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (pair<int, int> p : ans)
            cout << p.first + 1 << " " << p.second + 1 << endl;
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
