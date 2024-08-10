// https://www.naukri.com/code360/problems/unbounded-knapsack_1215029
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

#include <bits/stdc++.h>
int solve(int n, int w, vector<int>& profit, vector<int>& weight,
          vector<vector<int>>& dp) {
    if (n < 0 || w <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
      // not Take
    int notTake = solve(n - 1, w, profit, weight, dp);
    // take
    int take = 0;
    if (w - weight[n] >= 0)
        take = profit[n] + solve(n, w - weight[n], profit, weight, dp);
    return dp[n][w] = max(notTake, take);
}

int unboundedKnapsack(int n, int w, vector<int>& profit, vector<int>& weight) {
  // Write Your Code Here.
    // vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    // // return solve(n - 1, w, profit, weight, dp);
    // for (int wgt = 0; wgt <= w; wgt++) {
    //     dp[0][wgt] = ((int)(wgt / weight[0])) * profit[0];
    // }
    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j <= w; j++) {
    //         int notTake = dp[i - 1][j];
    //         // take
    //         int take = 0;
    //         if (weight[i] <= j)
    //             take = profit[i] + dp[i][j - weight[i]];
    //         dp[i][j] = max(notTake, take);
    //     }
    // }
    // return dp[n - 1][w];

    // vector<int>prev(w + 1, 0), curr(w + 1, 0);
    // for (int wgt = 0; wgt <= w; wgt++) {
    //     prev[wgt] = ((int)(wgt / weight[0])) * profit[0];
    // }
    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j <= w; j++) {
    //         int notTake = prev[j];
    //         // take
    //         int take = 0;
    //         if (weight[i] <= j)
    //             take = profit[i] + curr[j - weight[i]];
    //         curr[j] = max(notTake, take);
    //     }
    //     prev = curr;
    // }
    // return prev[w];

    vector<int> temp(w + 1, 0);
    for (int wgt = 0; wgt <= w; wgt++) {
        temp[wgt] = ((int)(wgt / weight[0])) * profit[0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            int notTake = temp[j];
            // take
            int take = 0;
            if (weight[i] <= j)
                take = profit[i] + temp[j - weight[i]];
            temp[j] = max(notTake, take);
        }
    }
    return temp[w];
}