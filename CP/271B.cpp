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

vector<int> primes;
vector<int> visited(1e7, true);

void init()
{
    for (int i = 2; i < 1e7; i++)
    {
        if (visited[i])
        {
            primes.push_back(i);
            for (int j = i + i; j < 1e7; j += i)
                visited[j] = false;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    rep(i, n)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int res = INT_MAX;
    rep(i, n)
    {
        int ans = 0;
        for (int j = 0; j < m; j++)
        {
            if (isPrime(arr[i][j]))
            {
                v[i][j] = 0;
            }
            else
            {
                int temp = *upper_bound(all(primes), arr[i][j]);
                temp -= arr[i][j];
                ans += temp;
                v[i][j] = temp;
            }
        }
        v[i][m] = ans;
        res = min(res, ans);
    }
    rep(i, m)
    {
        int temp = 0;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            temp += v[j][i];
        }
        ans += temp;
        res = min(ans, res);
    }
    cout << res << endl;

    // rep(i, n + 1)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cout << v[i][j] << " ";
    //     cout << endl;
    // }
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
        init();
        solve();
    }
    return 0;
}