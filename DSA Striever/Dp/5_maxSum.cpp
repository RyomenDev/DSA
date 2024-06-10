// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
// https://leetcode.com/problems/house-robber/description/
// ! Maximum sum of non - adjacent elements

#include <bits/stdc++.h> 

int solve(int idx, vector<int>& dp, vector<int>& v)
{
    if (idx == 0)
        return v[idx];
    if (idx < 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int pick = v[idx] + solve(idx - 2, dp, v);
    int notPick = solve(idx - 1, dp, v);
    return dp[idx] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int>& v) {
    // Write your code here.
    int n = v.size();
    // vector<int> dp(n + 1, -1);
    // return solve(n - 1, dp, v);
    // dp[0] = v[0];
    int prev = v[0], prevPrev = 0;
    for (int idx = 1; idx < n; idx++)
    {
        // int pick = v[idx]
        // if(idx>1)
            // int pick = dp[idx - 2]; // edge case idx=-1
        int pick = v[idx] + prevPrev;
        // int notPick = dp[idx - 1];
        int notPick = prev;
        // dp[idx] = max(pick, notPick);
        prevPrev = prev;
        prev = max(pick, notPick);
    }
    // return dp[n - 1];
    return prev;
}