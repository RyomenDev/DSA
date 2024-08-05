// https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471
// https://leetcode.com/problems/coin-change-ii/
// https://www.geeksforgeeks.org/problems/coin-change2448/1 

#include<bits/stdc++.h>
// long rec(int* a, int i, int val, int n, vector<vector<long>>& dp) {
//     if (i == n || val < 0)
//         return 0;
//     if (val == 0)
//         return 1;
//     if (dp[i][val] != -1)
//         return dp[i][val];
//     long notTake = rec(a, i, val - a[i], n, dp);
//     long take = rec(a, i + 1, val, n, dp);
//     dp[i][val] = take + notTake;
//     return dp[i][val];
// }

long rec(int* a, int i, int val, vector<vector<long>>& dp) {
    if (i < 0 || val < 0)
        return 0;
    if (val == 0)
        return 1;
    if (dp[i][val] != -1)
        return dp[i][val];
    long notTake = rec(a, i - 1, val, dp);
    long take = rec(a, i, val - a[i], dp);
    dp[i][val] = take + notTake;
    return dp[i][val];
}

long countWaysToMakeChange(int* a, int n, int val) {
  // Write your code here
    // vector<vector<long>> dp(n + 1, vector<long>(val + 1, -1));
    //   return rec(a, 0, val, n, dp);
    //   return rec(a, n-1, val, dp);
    vector<vector<long>> dp(n + 1, vector<long>(val + 1, 0));
    // for (int i = 0; i < n; i++) {
    //     dp[i][0] = 1;
    // }
    for (int t = 0; t <= val; t++) {
        if (t % a[0] == 0)
            dp[0][t] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= val; t++) {
            long notTake = dp[i - 1][t];
            long take = 0;
            if (a[i] <= t)
                take = dp[i][t - a[i]];
            dp[i][t] = take + notTake;
        }
    }
    return dp[n - 1][val];
}