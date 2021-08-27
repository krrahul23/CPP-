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
public:
    vector<string> invalidTransactions(vector<string> &t)
    {

        vector<string> name, city, res;
        vector<int> time, amt;

        for (int i = 0; i < t.size(); i++)
        {
            vector<string> x;

            string temp = "";
            for (int j = 0; j < t[i].size(); j++)
            {
                if (t[i][j] != ',')
                    temp += t[i][j];
                else
                {
                    x.push_back(temp);
                    temp = "";
                }
            }
            x.push_back(temp);

            name.push_back(x[0]);
            city.push_back(x[3]);
            time.push_back(stoi(x[1]));
            amt.push_back(stoi(x[2]));
        }

        unordered_set<int> ans;

        for (int i = 0; i < t.size(); i++)
        {

            if (amt[i] > 1000)
                ans.insert(i);
            for (int j = 0; j < t.size(); j++)
            {
                if (i != j && abs(time[i] - time[j]) <= 60 && city[i] != city[j] && name[i] == name[j])
                {
                    ans.insert(i);
                    ans.insert(j);
                }
            }
        }

        for (auto x : ans)
            res.push_back(t[x]);

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
