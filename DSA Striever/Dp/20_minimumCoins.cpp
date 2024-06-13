// https://www.naukri.com/code360/problems/minimum-elements_3843091
// https://leetcode.com/problems/coin-change/
// https://www.geeksforgeeks.org/problems/min-coin5549/1
// ! Minimum Coins _ DP on Subsequences _ Infinite Supplies Pattern

#include <bits/stdc++.h>
#define ll long long
ll solve(int idx, int T, vector<vector<int>>& dp, vector<int>& num) {
    if (idx == 0) {
        if (T % num[idx] == 0)
            return T / num[idx];
        return INT_MAX;
    }
    if (dp[idx][T] != -1)
        return dp[idx][T];
    ll pick = num[idx] <= T ? 1 + solve(idx, T - num[idx], dp, num) : INT_MAX;
    ll notPick = solve(idx - 1, T, dp, num);
    return dp[idx][T] = min(pick, notPick);
}
int minimumElements(vector<int>& num, int x) {
  // Write your code here.
  // int n = num.size();
  // vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
  // int ans =solve(n-1,x,dp,num);
  // return ans>=INT_MAX?-1:ans;

    int n = num.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));
    for (int T = 0; T <= x; T++) {
        if (T % num[0] == 0)
            dp[0][T] = T / num[0];
        else
            dp[0][T] = INT_MAX;
    }
    for (int idx = 1; idx < n; idx++) {
        for (int T = 0; T <= x; T++) {
            ll pick = num[idx] <= T ? 1 + dp[idx][T - num[idx]] : INT_MAX;
            ll notPick = dp[idx - 1][T];
            dp[idx][T] = min(pick, notPick);
        }
    }
    int ans = dp[n - 1][x];
    return ans >= INT_MAX ? -1 : ans;
}