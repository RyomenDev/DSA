// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954 
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// ! Subset Sum Equal To K

/*
^ subsequence : contiguous | non -contiguous - maintain relative order
^ subarray : contiguous - maintain relative order
^ subset : my or may not contiguous - do not maintain relative order
*/
/*
% 1: express everything in idx , target
% 2: explore possibilities of that idx - whether it is part of subsequence or not
*/

#include <bits/stdc++.h>
// O(n*target)
bool solve(int idx, int sum, int k, vector<vector<int>>& dp, vector<int>& arr) {
    if (sum == k)
        return true;
    if (idx < 0 || sum> k)
        return false;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
      // pick
    bool pick = solve(idx - 1, sum + arr[idx], k, dp, arr);
    // not pick
    bool notPick = solve(idx - 1, sum, k, dp, arr);
    return dp[idx][sum] = (pick || notPick);
}
bool subsetSumToK(int n, int k, vector<int>& arr) {
    // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // return solve(n - 1, 0, k, dp, arr);

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    //sum of 0 can always be achieved with an empty subset
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++) {
        for (int tgt = 1; tgt <= k; tgt++) {
            bool pick = (tgt >= arr[idx]) ? dp[idx - 1][tgt - arr[idx]] : 0;
            // not pick
            bool notPick = dp[idx - 1][tgt];
            dp[idx][tgt] = (pick || notPick);
        }
    }
    return dp[n - 1][k];


    // vector<int> prev(k + 1, 0), curr(k + 1, 0);
    // // sum of 0 can always be achieved with an empty subset
    // prev[0] = curr[0] = 1;
    // if (arr[0] <= k) {
    //     prev[arr[0]] = 1;
    // }
    // for (int idx = 1; idx < n; idx++) {
    //     for (int tgt = 1; tgt <= k; tgt++) {
    //         bool pick = (tgt >= arr[idx]) ? prev[tgt - arr[idx]] : 0;
    //         // not pick
    //         bool notPick = prev[tgt];
    //         curr[tgt] = (pick || notPick);
    //     }
    //     prev = curr;
    // }
    // return prev[k];
}