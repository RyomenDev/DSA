// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
// https://leetcode.com/problems/rotting-oranges/description/
// Rotten Oranges

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define vvi vector<vector<int>>
class Solution
{
    int bfs(vvi &grid)
    {
        int ans = 0;
        int r = grid.size(), c = grid[0].size();
        vvi vis(r, vector<int>(c, 0));

        queue<pair<pair<int, int>, int>> q;
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, cnt});
                    vis[i][j] = 2;
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            pair<pair<int, int>, int> node = q.front();
            q.pop();
            int x = node.first.first;
            int y = node.first.second;
            cnt = node.second; // count
            ans = max(ans, cnt);
            for (auto it : dir)
            {
                int xx = x + it.first;
                int yy = y + it.second;
                if (xx >= 0 && xx < r && yy >= 0 && yy < c &&
                    grid[xx][yy] == 1 && vis[xx][yy] == 0)
                {
                    q.push({{xx, yy}, cnt + 1});
                    vis[xx][yy] = 2;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        return bfs(grid);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends