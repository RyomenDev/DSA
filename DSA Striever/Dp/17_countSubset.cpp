// https://www.naukri.com/code360/problems/number-of-subsets_3952532
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// https://leetcode.com/problems/subarray-sum-equals-k/submissions/1220184229/ (-ve)
// !  Count Subsets with Sum K

/*
^ EXPRESS IN TERMS OF (idx,target)
^ EXPLORE ALL POSSIBILITIES
^ SUM ALL OF THE POSSIBILITIES AND RETURN
*/
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

int findWays(vector<int>& num, int k) {
    int n = arr.size();
    // map<pair<int, int>, int> dp;
    // return solve(n - 1, k, dp, num);

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
      // num[0]=0
    if (num[0] != 0 && num[0] <= k)
        dp[0][num[0]] = 1;
    for (int idx = 1; idx < n; idx++) {
        for (int sum = 0; sum <= k; sum++) {
            int pick = (num[idx] <= sum) ? dp[idx - 1][sum - num[idx]] % MOD : 0;
            int notPick = dp[idx - 1][sum] % MOD;
            dp[idx][sum] = (pick + notPick) % MOD;
        }
    }
    return dp[n - 1][k];
}

