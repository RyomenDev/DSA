// https://www.naukri.com/code360/problems/total-unique-paths_1081470
// https://leetcode.com/problems/unique-paths/description/
// https://www.geeksforgeeks.org/problems/number-of-unique-paths5339/1
// ! Unique Paths

#include <bits/stdc++.h>

int solve(int i, int j, vector<vector<int>>& dp) { // O(2*m*n) + O(m+n)
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int left = 0, up = 0;
    if (i > 0)
        left = solve(i - 1, j, dp);
    if (j > 0)
        up = solve(i, j - 1, dp);
    return dp[i][j] = left + up;
}

int uniquePaths(int m, int n) {
  // Write your code here.
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // // return solve(m - 1, n - 1, dp);
    // dp[0][0] = 1;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i == 0 && j == 0)
    //             continue;
    //         int right = 0, down = 0;
    //         if (i > 0)
    //             right = dp[i - 1][j];
    //         if (j > 0)
    //             down = dp[i][j - 1];
    //         dp[i][j] = right + down;
    //     }
    // }
    // return dp[m - 1][n - 1];

    vector<int> prevRow(n, 0);
    prevRow[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          //   int down = 0;
          //   int right = prevRow[j];
          //   if (j > 0)
          //     down = prevRow[j - 1];
          //   prevRow[j] = right + down;
            if (j > 0)
                prevRow[j] += prevRow[j - 1];
        }
    }

    return prevRow[n - 1];
}