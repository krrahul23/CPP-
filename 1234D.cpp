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

void solve()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    set<int> s[26];

    rep(i, str.size())
    {
        int key = str[i] - 'a';
        s[key].insert(i + 1);
    }

    rep(i, n)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b;
            char c;
            cin >> b >> c;

            rep(i, 26)
            {
                if (s[i].count(b))
                {
                    s[i].erase(s[i].find(b));
                }
            }
            int index = c - 'a';
            s[index].insert(b);
        }
        else
        {
            int d, e;
            cin >> d >> e;
            int ans = 0;
            rep(i, 26)
            {
                if (s[i].lower_bound(d) != s[i].lower_bound(e))
                    ans++;
                else if (s[i].count(e) || s[i].count(d))
                    ans++;
            }
            cout << ans << endl;
        }
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
