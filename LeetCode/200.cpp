#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};
    vector<vector<bool>> visited;
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                continue;
            else if (!visited[x][y] && grid[x][y] == '1')
                dfs(x, y, grid);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited = vector<vector<bool>>(n + 5, vector<bool>(m + 5));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                    ans++, dfs(i, j, grid);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}