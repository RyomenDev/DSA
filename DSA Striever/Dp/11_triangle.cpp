// https://www.naukri.com/code360/problems/triangle_1229398
// ! triangle

#include <bits/stdc++.h>
int solve(int i, int j, vector<vector<int>>& dp,
          vector<vector<int>>& triangle) {
    if (i < 0 || j < 0 || j >= triangle[i].size()) // Correct boundary checks
        return INT_MAX;
    if (i == 0 && j == 0)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, dp, triangle);
    int leftDiag = solve(i - 1, j - 1, dp, triangle);
    return dp[i][j] = triangle[i][j] + min(up, leftDiag);
}

int solve(int i, int j, vector<vector<int>>& dp,
          vector<vector<int>>& triangle) {
    if (i == triangle.size() - 1) // Correct boundary checks
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i + 1, j, dp, triangle);
    int leftDiag = solve(i + 1, j + 1, dp, triangle);
    return dp[i][j] = triangle[i][j] + min(up, leftDiag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    // Write your code here.
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // int ans = INT_MAX;
    // for (int j = 0; j < n; j++) {
    //     ans = min(ans, solve(n - 1, j, dp, triangle));
    // }
    // return ans;

    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solve(0,0, dp, triangle);

    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (i == 0 && j == 0)
                continue;
            // ensures that the element triangle[i][j] has a corresponding
            // element directly above it in the previous row (i - 1).
            int down = (j < triangle[i - 1].size()) ? dp[i - 1][j] : INT_MAX;
            // condition checks if there is an element in the previous row 
            // that is to the diagonal left of the current element triangle[i][j].
            int rightDiag = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
            dp[i][j] = triangle[i][j] + min(down, rightDiag);
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;

    vector<int> prevRow(m, 0);
    prevRow[0] = triangle[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (i == 0 && j == 0)
                continue;
            // ensures that the element triangle[i][j] has a corresponding
            // element directly above it in the previous row (i - 1).
            int down = (j < triangle[i - 1].size()) ? prevRow[j] : INT_MAX;
            // condition checks if there is an element in the previous row 
            // that is to the diagonal left of the current element triangle[i][j].
            int rightDiag = (j > 0) ? prevRow[j - 1] : INT_MAX;
            dp[i][j] = triangle[i][j] + min(down, rightDiag);
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        ans = min(ans, dp[j]);
    }
    return ans;

    // vector<int> prevRow(n, 0);
    // prevRow[0] = triangle[0][0];
    // for (int i = 1; i < n; i++) {
    //     vector<int> currRow(n, 0);
    //     for (int j = 0; j < triangle[i].size(); j++) {
    //         if (i == 0 && j == 0)
    //             continue;
    //           // ensures that the element triangle[i][j] has a corresponding
    //           // element directly above it in the previous row (i - 1).
    //         int down = (j < triangle[i - 1].size()) ? prevRow[j] : INT_MAX;
    //         // condition checks if there is an element in the previous row
    //         // that is to the diagonal left of the current element triangle[i][j].
    //         int rightDiag = (j > 0) ? prevRow[j - 1] : INT_MAX;
    //         currRow[j] = triangle[i][j] + min(down, rightDiag);
    //     }
    //     prevRow = currRow;
    // }

    // int ans = INT_MAX;
    // for (int j = 0; j < n; j++) {
    //     ans = min(ans, prevRow[j]);
    // }
    // return ans;
}