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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(all(v));
    if (n == 2)
    {
        cout << 1 << endl;
    }
    else
    {
        int diff = v[1].first - v[0].first;
        int diff2 = v[2].first - v[1].first;
        int diff3 = v[2].first - v[0].first;
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first - v[i - 1].first != diff)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << v[0].second << endl;
            return;
        }
        flag = false;
        for (int i = 2; i < n; i++)
        {
            if (v[i].first - v[i - 1].first != diff2)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << v[0].second << endl;
            return;
        }
        flag = !(n >= 4);
        for (int i = 3; i < n; i++)
        {
            if (v[i].first - v[i - 1].first != diff3)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << v[1].second << endl;
            return;
        }
        flag = false;
        int index = -1;
        for (int i = 1; i < n; i++)
        {
            if (!flag && v[i].first - v[i - 1].first != diff)
            {
                if (i < n - 1 && v[i + 1].first - v[i - 1].first == diff || (i == n - 1))
                {
                    index = v[i].second;
                    flag = true;
                    i++;
                }
                else if (i < n - 1 && v[i + 1].first - v[i - 1].first != diff)
                {
                    cout << -1 << endl;
                    return;
                }
            }
            else if (flag && v[i].first - v[i - 1].first != diff)
            {
                cout << -1 << endl;
                return;
            }
        }
        cout << index << endl;
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
