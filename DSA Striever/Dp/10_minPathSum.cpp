// https://www.naukri.com/code360/problems/minimum-path-sum_985349
// ! minimum path sum


#include <bits/stdc++.h>
int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
    if (i < 0 || j < 0)
        return INT_MAX;
    if (i == 0 && j == 0)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = solve(i - 1, j, dp, grid);
    int up = solve(i, j - 1, dp, grid);
    return dp[i][j] = grid[i][j] + min(left, up);
}
int minSumPath(vector<vector<int>>& grid) {
  // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n - 1, m - 1, dp, grid);

    // dp[0][0] = grid[0][0];
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (i == 0 && j == 0)
    //             continue;
    //         int right = i > 0 ? dp[i - 1][j] : INT_MAX;
    //         int down = j > 0 ? dp[i][j - 1] : INT_MAX;
    //         dp[i][j] = grid[i][j] + min(right, down);
    //     }
    // }
    // return dp[n - 1][m - 1];

    vector<int> prevRow(m, 0);
    prevRow[0] = grid[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;
            int right = i > 0 ? prevRow[j] : INT_MAX;
            int down = j > 0 ? prevRow[j - 1] : INT_MAX;
            prevRow[j] = grid[i][j] + min(right, down);
        }
    }
    return prevRow[m - 1];
}