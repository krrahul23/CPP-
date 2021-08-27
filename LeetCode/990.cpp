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

struct DSU
{
private:
    vector<int> e;

public:
    DSU(int n) { e = vector<int>(n + 5); }
    int get(int x) { return e[x] < 0 ? x : get(e[x]); }
    int same_set(int a, int b) { return get(a) == get(b); }
    int unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x == y)
            return false;
        else
        {
            if (e[x] > e[y])
                swap(x, y);
            e[x] += e[y];
            e[y] = x;
        }
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU diff = DSU(30);
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            string s = equations[i];
            if (s[1] == '=')
                diff.unite(s[0] - 'a', s[3] - 'a');
            else
                continue;
        }

        for (int i = 0; i < n; i++)
        {
            string s = equations[i];
            if (s[1] == '!')
            {

                if (diff.same_set(s[0] - 'a', s[3] - 'a'))
                    return false;
            }
            else
                continue;
        }
        return true;
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
