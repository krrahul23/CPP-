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

typedef pair<int, int> pii;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        ListNode *root = new ListNode();
        ListNode *temp = root;
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != NULL)
                pq.push({lists[i]->val, i});
        }

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            root->next = lists[node];
            if (lists[node]->next != NULL)
            {
                lists[node] = lists[node]->next;
                pq.push({lists[node]->val, node});
            }
            root = root->next;
        }

        root->next = NULL;
        return temp->next;
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
