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
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 5);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (auto j : nums)
            {
                if (i - j >= 0)
                    dp[i] += dp[i - j];
            }
        }
        return dp[target];
    }
};

void solve()
{
    vector<int> nums = {10,
                        20,
                        30,
                        40,
                        50,
                        60,
                        70,
                        80,
                        90,
                        100,
                        110,
                        120,
                        130,
                        140,
                        150,
                        160,
                        170,
                        180,
                        190,
                        200,
                        210,
                        220,
                        230,
                        240,
                        250,
                        260,
                        270,
                        280,
                        290,
                        300,
                        310,
                        320,
                        330,
                        340,
                        350,
                        360,
                        370,
                        380,
                        390,
                        400,
                        410,
                        420,
                        430,
                        440,
                        450,
                        460,
                        470,
                        480,
                        490,
                        500,
                        510,
                        520,
                        530,
                        540,
                        550,
                        560,
                        570,
                        580,
                        590,
                        600,
                        610,
                        620,
                        630,
                        640,
                        650,
                        660,
                        670,
                        680,
                        690,
                        700,
                        710,
                        720,
                        730,
                        740,
                        750,
                        760,
                        770,
                        780,
                        790,
                        800,
                        810,
                        820,
                        830,
                        840,
                        850,
                        860,
                        870,
                        880,
                        890,
                        900,
                        910,
                        920,
                        930,
                        940,
                        950,
                        960,
                        970,
                        980,
                        990,
                        111};
    Solution a = Solution();

    int ans = a.combinationSum4(nums, 999);
    cout << ans << endl;
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
