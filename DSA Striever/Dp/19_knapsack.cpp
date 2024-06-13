// https://www.naukri.com/code360/problems/0-1-knapsack_920542
// ! 0 1 Knapsack
/*
^ eXPRESS IN TERMS OF (idx,target)
^ EXPLORE ALL POSSIBILITIES pick/not pick
^ MAX(all possibilities)
*/
#include <bits/stdc++.h>
int solve(int idx, int w, vector<vector<int>>& dp, vector<int> weight,
          vector<int> value) {
    if (idx == 0) {
        if (weight[idx] <= w)
            return value[idx];
        return 0;
    }
    if (dp[idx][w] != -1)
        return dp[idx][w];
    int pick = (weight[idx] <= w)
        ? value[idx] + solve(idx - 1, w - weight[idx], dp, weight, value)
        : 0;
    int notPick = solve(idx - 1, w, dp, weight, value);
    return dp[idx][w] = max(pick, notPick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Write your code here
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solve(n - 1, maxWeight, dp, weight, value);

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

   // Initialize the dp array for the first item
    for (int w = weight[0]; w <= maxWeight; w++) {
        dp[0][w] = value[0];
    }

    // Fill the dp array
    for (int idx = 1; idx < n; idx++) {
        for (int w = 0; w <= maxWeight; w++) {
            int pick = (weight[idx] <= w) ? value[idx] + dp[idx - 1][w - weight[idx]] : 0;
            int notPick = dp[idx - 1][w];
            dp[idx][w] = max(pick, notPick);
        }
    }

    return dp[n - 1][maxWeight];

    
}