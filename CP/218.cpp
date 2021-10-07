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

class Solution
{

    struct point
    {
        int dist, height, type;
        point(int d, int h, int t)
        {
            dist = d;
            height = h;
            type = t;
        }
    };

    static bool comp(point p1, point p2)
    {

        if (p1.dist < p2.dist)
            return true; // --> no clash

        else if (p1.dist == p2.dist)
        {

            /* start-start clash */

            if (p1.type == 0 and p2.type == 0)
                return p1.height > p2.height;

            /* end-end clash */

            else if (p1.type == 1 and p2.type == 1)
                return p1.height < p2.height;

            /* start-end clash */

            else
                return p1.type == 0;
        }

        else
            return false;
    }

    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {

        vector<vector<int>> res;
        vector<point> p;

        multiset<int> s;
        s.insert(0);

        for (auto b : buildings)
        {
            p.push_back(point(b[0], b[2], 0)); // --> start of building b (startDist, height, 0 denotes start)
            p.push_back(point(b[1], b[2], 1)); // --> end of building b (endDist, height, 1 denotes end)
        }

        sort(p.begin(), p.end(), comp);

        for (auto pt : p)
        {
            int prev_max = *s.rbegin();

            if (pt.type == 0)
                s.insert(pt.height);
            else
                s.erase(s.find(pt.height)); // --> This will erase only one instance from multiset
                                            // --> (Simple erase will remove all instances)

            int curr_max = *s.rbegin();

            if (curr_max != prev_max)
                res.push_back({pt.dist, curr_max});
        }

        return res;
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
