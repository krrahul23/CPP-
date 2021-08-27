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
int n, m;
bool valid(int i, int j)
{
    return ((i >= 0 && j >= 0) && (i < n && j < m));
}
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};

void solve()
{
    // int n, m;
    vector<string> grid;
    vector<vector<bool>> visited;

    cin >> n >> m;
    grid = vector<string>(n + 3);
    visited = vector<vector<bool>>(n + 3, vector<bool>(m + 5, false));
    rep(i, m)
    {
        cin >> grid[i];
    }
    rep(i, n)
    {
        rep(j, m) cout << grid[i][j];
        cout << endl;
    }
    bool ans = true;
    rep(i, n)
    {
        rep(j, m)
        {
            if (grid[i][j] == 'B')
            {
                rep(k, 4)
                {
                    int x = di[k] + i;
                    int y = dj[k] + j;
                    if (valid(x, y) && grid[x][y] == '.')
                        grid[x][y] = '#';
                }
            }
        }
    }
    if (grid[n - 1][m - 1] == '#')
        ans = false;
    else
    {
        queue<pair<int, int>> q;
        q.push({n - 1, m - 1});
        while (q.size())
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = di[i] + p.first;
                int y = dj[i] + p.second;
                if (valid(x, y) && !visited[x][y] && grid[x][y] != '#')
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        rep(i, n)
        {
            rep(j, m)
            {
                if ((visited[i][j] && grid[i][j] == 'B') || (!visited[i][j] && grid[i][j] == 'G'))
                {
                    ans = false;
                    break;
                }
            }
            if (!ans)
                break;
        }
    }

    // if (ans)
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;
}

int32_t main()
{
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
