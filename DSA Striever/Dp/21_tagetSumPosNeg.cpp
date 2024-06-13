// https://www.naukri.com/code360/problems/target-sum_4127362
// https://leetcode.com/problems/target-sum/
// https://www.geeksforgeeks.org/problems/target-sum-1626326450/1
// ! Target Sum

#include <bits/stdc++.h>
int MOD = 1e9 + 7;
int solve(int idx, int k, map<pair<int, int>, int>& dp, vector<int>& arr) {
    if (idx == 0) {
        if (k == 0 && arr[idx] == 0)
            return 2;
        if (k == arr[idx] || k == 0)
            return 1;
        else
            return 0;
    }
    if (idx < 0 || k < 0)
        return 0;

    pair<int, int> key = {idx, k};
    if (dp.find(key) != dp.end())
        return dp[key];
      // pick
    int pick = solve(idx - 1, k - arr[idx], dp, arr) % MOD;
    // not pick
    int notPick = solve(idx - 1, k, dp, arr) % MOD;
    return dp[key] = (pick + notPick) % MOD;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int diff = totalSum - d;
    if (diff < 0 || diff & 1)
        return 0;
    int newTarget = diff / 2;

    map<pair<int, int>, int> dp;
    return solve(n - 1, newTarget, dp, arr);
}

int targetSum(int n, int target, vector<int>& arr) {
  // Write your code here.
    return countPartitions(n, target, arr);
}
