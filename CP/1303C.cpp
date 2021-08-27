#include <bits/stdc++.h>
const int maxn = 205;
int t;
int mp[maxn][maxn];
int cnt[maxn];
int vis[maxn];
using namespace std;
string s;
vector<int> ans;
void dfs(int x)
{
    ans.push_back(x);
    vis[x] = 1;
    for (int i = 1; i <= 26; i++)
    {
        if (!vis[i] && mp[x][i])
        {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        ans.clear();
        memset(mp, 0, sizeof(mp));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < s.size(); i++)
        {
            int n = s[i] - 'a' + 1;
            int m = s[i - 1] - 'a' + 1;
            mp[n][m] = 1;
            mp[m][n] = 1;
        }
        for (int i = 1; i <= 26; i++)
            for (int j = 1; j <= 26; j++)
                if (mp[i][j])
                    cnt[i]++;
        int f = 0;
        for (int i = 1; i <= 26; i++)
        {
            //cout << cnt[i] << endl;
            if (cnt[i] >= 3)
                f = 1;
        }
        if (f)
            cout << "NO" << endl;
        else
        {
            for (int i = 1; i <= 26; i++)
                if (cnt[i] <= 1 && !vis[i])
                    dfs(i);
            for (int i = 1; i <= 26; i++)
            {
                //out << vis[i] << endl;
                if (!vis[i])
                    f = 1;
            }
            if (f)
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                for (auto i : ans)
                {
                    char an = i - 1 + 97;
                    cout << an;
                }
                cout << endl;
            }
        }
    }
}