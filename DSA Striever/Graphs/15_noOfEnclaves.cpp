// https://www.geeksforgeeks.org/problems/number-of-enclaves/1

class Solution {
    // Directions for moving in the four cardinal directions
    vector<pair<int, int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

    // DFS function to explore the grid
    bool solve(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int& cnt) {
        int n = grid.size(), m = grid[0].size();
        // Base conditions
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
            return false;
        vis[i][j] = 1; // Mark the cell as visited
        if (!grid[i][j])
            return false;
        cnt++; // Increase the count of land cells

        // Check if this cell is on the boundary
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            return true;
        }

        // Explore all four directions
        bool touchesBoundary = false;
        for (auto it : dir) {
            int x = i + it.first, y = j + it.second;
            touchesBoundary |= solve(x, y, vis, grid, cnt);
        }
        return touchesBoundary;
    }

public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix
        int ans = 0;

        // Iterate over all cells in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                if (!vis[i][j] && grid[i][j] == 1) {
                    if (!solve(i, j, vis, grid, cnt)) {
                        ans += cnt;
                    }
                }
            }
        }
        return ans; // Return the count of enclaved land cells
    }
};
