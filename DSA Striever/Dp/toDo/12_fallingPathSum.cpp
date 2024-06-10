// https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998
// https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
// https://leetcode.com/problems/minimum-falling-path-sum/description/
// ! Minimum/Maximum Falling Path Sum

#include <bits/stdc++.h>

int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
    if (i < 0 || j < 0 || j >= matrix[0].size())
        return INT_MIN;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != INT_MIN)
        return dp[i][j];
    int up = solve(i - 1, j, dp, matrix);
    int upright = solve(i - 1, j - 1, dp, matrix);
    int upleft = solve(i - 1, j + 1, dp, matrix);
    return dp[i][j] = matrix[i][j] + max(up, max(upright, upleft));
}

int getMaxPathSum(vector<vector<int>>& matrix) {
  //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    int ans = INT_MIN;
    for (int i = 0; i < m; i++) {
        ans = max(ans, solve(n - 1, i, dp, matrix));
    }
    return ans;
}