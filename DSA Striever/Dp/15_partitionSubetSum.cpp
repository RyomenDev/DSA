// https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980
// https://leetcode.com/problems/partition-equal-subset-sum/description/
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
// ! Partition Equal Subset Sum

#include <bits/stdc++.h>

bool solve(int idx, int sum, int k, vector<vector<int>>& dp, vector<int>& arr) {
    if (sum == k)
        return true;
    if (idx < 0 || sum > k)
        return false;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
      // pick
    bool pick = solve(idx - 1, sum + arr[idx], k, dp, arr);
    // not pick
    bool notPick = solve(idx - 1, sum, k, dp, arr);
    return dp[idx][sum] = (pick || notPick);
}

bool canPartition(vector<int>& arr, int n) {
  // Write your code here.
    int k = accumulate(arr.begin(), arr.end(), 0);
    if (k % 2 == 0)
        k = k / 2;
    else
        return false;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, 0, k, dp, arr);
}
