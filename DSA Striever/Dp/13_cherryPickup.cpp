// https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885
// https://leetcode.com/problems/cherry-pickup-ii/description/
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

//! choclate pickup

/*
 ^ Rules :
 ^ express everything in terms (i1,j1) & (i2,j2);
 ^ explore all the paths
 ^ find max/min as asked
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j1, int j2, vector<vector<vector<int>>>& dp,
          vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return INT_MIN;
    if (i == n - 1)
        return grid[i][j1] + ((j1 != j2) ? grid[i][j2] : 0);

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
      // All 9 paths
    int currMax = INT_MIN;
    for (int jj1 = -1; jj1 <= 1; jj1++) {
        for (int jj2 = -1; jj2 <= 1; jj2++) {
            int curr = grid[i][j1] + solve(i + 1, j1 + jj1, j2 + jj2, dp, grid);
            if (j1 != j2)
                curr += grid[i][j2];
            currMax = max(currMax, curr);
        }
    }
    return dp[i][j1][j2] = currMax;
}

int maximumChocolates(int r, int c, vector<vector<int>>& grid) {
    // int n = grid.size(), m = grid[0].size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // return solve(0, 0, c - 1, dp, grid);

    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // Initialize the last row of dp table
    for (int jj1 = 0; jj1 < m; jj1++) {
        for (int jj2 = 0; jj2 < m; jj2++) {
            dp[n - 1][jj1][jj2] =
                grid[n - 1][jj1] + ((jj1 != jj2) ? grid[n - 1][jj2] : 0);
        }
    }

    // Bottom-up DP
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int currMax = INT_MIN;
                for (int jj1 = -1; jj1 <= 1; jj1++) {
                    for (int jj2 = -1; jj2 <= 1; jj2++) {
                        int newJ1 = j1 + jj1, newJ2 = j2 + jj2;
                        if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m) {
                            int curr = grid[i][j1] + dp[i + 1][newJ1][newJ2];
                            if (j1 != j2)
                                curr += grid[i][j2];
                            currMax = max(currMax, curr);
                        }
                    }
                }
                dp[i][j1][j2] = currMax;
            }
        }
    }

    // Return the result for the top-left cell
    return dp[0][0][m - 1];
}
