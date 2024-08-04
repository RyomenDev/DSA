// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

// https://leetcode.com/problems/surrounded-regions/

#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
class Solution {
    vector<pair<int, int>>dir{{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int i, int j, vvi& vis, vvc& mat) {
        int n = mat.size(), m = mat[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 'X' || vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        for (auto it : dir) {
            int a = it.first, b = it.second;
            dfs(i + a, j + b, vis, mat);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vvi vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O') {
                dfs(i, 0, vis, mat);
            }
            if (mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat);
            }
        }
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 'O') {
                dfs(0, j, vis, mat);
            }
            if (mat[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, mat);
            }
        }
        vector<vector<char>>ans = mat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O' && vis[i][j] == 0)
                    ans[i][j] = 'X';
            }
        }
        return ans;
    }
};
