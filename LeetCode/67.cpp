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
    string addBinary(string a, string b);
};

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0)
        {
            int d1 = i >= 0 ? a[i] - '0' : 0;
            int d2 = j >= 0 ? b[j] - '0' : 0;
            int d;
            if (d1 == 1 && d2 == 1)
            {
                d = carry;
                carry = 1;
            }
            else if (d1 == 0 && d2 == 0)
            {
                d = carry;
                carry = 0;
            }
            else
            {
                d = carry ^ 1; // Or d = carry ^ (d1 ^ d2);
                carry = (d == 0) ? 1 : 0;
            }
            res = to_string(d) + res;
            i--, j--;
        }

        if (carry)
            res = to_string(carry) + res;

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
