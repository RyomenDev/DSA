// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

// https://leetcode.com/problems/01-matrix/submissions/1341887113/

#define vvi vector<vector<int>>
class Solution {
    vector<pair<int, int>>dir{{1,0},{-1,0},{0,-1},{0,1}};
    void bfs(vvi& grid, vvi& vis, vvi& dis) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            pair<pair<int, int>, int>temp = q.front();
            q.pop();
            int ii = temp.first.first, jj = temp.first.second, val = temp.second;
            dis[ii][jj] = val;
            for (auto it : dir) {
                int a = it.first, b = it.second;
                int ni = ii + a, nj = jj + b, nval = val + 1;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                    continue;
                if (!vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    q.push({{ni,nj},nval});
                }
            }
        }
    }
public:
  // Function to find distance of nearest 1 in the grid for each cell.
    vvi nearest(vvi& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        vvi vis(m, vector<int>(n, 0));
        vvi dis(m, vector<int>(n, 0));

        bfs(grid, vis, dis);

        return dis;
    }
};
