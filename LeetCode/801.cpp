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

class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> v(nums1.size(), vector<int>(nums2.size(), -1));
        int ans = helper(nums1, nums2, v, 0, 0);
        return ans;
    }

private:
    int helper(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &v, int index, int swapped)
    {
        int n = nums1.size();
        if (index == n)
            return 0;

        if (v[index][swapped] != -1)
            return v[index][swapped];
        int prev1 = INT_MIN;
        int prev2 = INT_MIN;
        if (index > 0)
        {
            prev1 = swapped ? nums2[index - 1] : nums1[index - 1];
            prev2 = swapped ? nums1[index - 1] : nums2[index - 1];
        }
        int a = INT_MAX;
        if (prev1 < nums1[index] && prev2 < nums2[index])
        {
            a = helper(nums1, nums2, v, index + 1, 0);
        }
        int b = INT_MAX;
        if (prev2 < nums1[index] && prev1 < nums2[index] && nums1[index] != nums2[index])
        {
            b = helper(nums1, nums2, v, index + 1, 1);
            if (b != INT_MAX)
                b += 1;
        }
        return v[index][swapped] = min(a, b);
    }
};

void solve()
{
    Solution *a = new Solution();
    vector<int> v1 = {1, 3, 5, 4};
    vector<int> v2 = {1, 2, 3, 7};
    int ans = a->minSwap(v1, v2);

    cout << ans << endl;
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
