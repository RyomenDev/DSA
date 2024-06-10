// https://www.naukri.com/code360/problems/maze-obstacles_977241
// https://leetcode.com/problems/unique-paths-ii/description/
// ! Unique Paths II 

#include <bits/stdc++.h>
#define ll long long
int MOD = 1e9 + 7;
ll solve(int i, int j, vector<vector<ll>>& dp,
         vector<vector<int>>& mat) { // O(2*m*n) + O(m+n)
    //   if (i < 0 || j < 0 || mat[i][j] == -1)
    //     return 0;
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll left = 0, up = 0;
    if (i > 0 && mat[i - 1][j] != -1)
        left = solve(i - 1, j, dp, mat);
    if (j > 0 && mat[i][j - 1] != -1)
        up = solve(i, j - 1, dp, mat);
    return dp[i][j] = (left + up) % MOD;
}
int mazeObstacles(int n, int m, vector< vector< int> >& mat) {
  // Write your code here.
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return solve(n - 1, m - 1, dp, mat) % MOD;

    // if (mat[0][0] == -1 || mat[n - 1][m - 1] == -1)
    //     return 0;
    // dp[0][0] = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (i == 0 && j == 0)
    //             continue;
    //         int right = 0, down = 0;
    //         if (i > 0 && mat[i - 1][j] != -1)
    //             right = dp[i - 1][j];
    //         if (j > 0 && mat[i][j - 1] != -1)
    //             down = dp[i][j - 1];
    //         dp[i][j] = (right + down) % MOD;
    //     }
    // }
    // return dp[n - 1][m - 1];

    if (mat[0][0] == -1 || mat[n - 1][m - 1] == -1)
        return 0;
    vector<int> prevRow(m, 0);
    prevRow[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;
            int right = 0, down = 0;
            if (i > 0 && mat[i - 1][j] != -1)
                right = prevRow[j];
            if (j > 0 && mat[i][j - 1] != -1)
                down = prevRow[j - 1];
            prevRow[j] = (right + down) % MOD;
        }
    }
    return prevRow[m - 1];
}