// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
// https://leetcode.com/problems/number-of-islands/
// Find the number of island

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//O(n^2)

class Solution
{
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (auto it : dir)
        {
            int x = i + it.first;
            int y = j + it.second;
            dfs(grid, x, y);
        }
        return;
    }
    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
            for (auto it : dir)
            {
                int xx = x + it.first;
                int yy = y + it.second;
                if (xx >= 0 && yy >= 0 && xx < n && yy < m && grid[xx][yy] == '1')
                {
                    grid[xx][yy] = '0';
                    q.push({xx, yy});
                }
            }
        }
        return;
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    // dfs(grid, i, j);
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    // cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends