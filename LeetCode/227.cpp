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
    int getPriority(char &c)
    {
        if (c == '+' || c == '-')
            return 0;
        else
            return 1;
    }

    int perform_op(char &c, int &a, int &b)
    {
        if (c == '+')
            return a + b;
        else if (c == '-')
            return a - b;
        else if (c == '*')
            return a * b;
        else
            return a / b;
    }

    int calculate(string s)
    {
        stack<int> nums;
        stack<char> ops;

        for (int i = 0; i < s.size();)
        {
            // skip spaces
            while (i < s.size() && s[i] == ' ')
                ++i;

            // a digit found, traverse till the end of potential end of number
            if (i < s.size() && isdigit(s[i]))
            {
                int number = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    number = number * 10 + (s[i] - '0');
                    ++i;
                }
                nums.emplace(number);
            }
            // if the current char is an operator
            else if (i < s.size())
            {
                // A lower priority op can't be put
                // before finishing a higher priority op
                // S: *, + ====> * should be performed first
                // S: +, * ====> Allowed
                while (!ops.empty() && getPriority(s[i]) <= getPriority(ops.top()))
                {
                    // perform the operation and put the sub expression result
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    nums.emplace(perform_op(ops.top(), first, second));
                    ops.pop();
                }
                ops.emplace(s[i]);
                ++i;
            }
        }

        // evaluate the expression with the remaining operators
        while (!ops.empty())
        {
            // perform the operation and put the sub expression result
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            nums.pop();
            nums.emplace(perform_op(ops.top(), first, second));
            ops.pop();
        }

        return nums.top();
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
