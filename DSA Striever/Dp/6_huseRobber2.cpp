// https://www.naukri.com/code360/problems/house-robber_839733
// https://leetcode.com/problems/house-robber-ii/
// !  House Robber II

#include <bits/stdc++.h>
#define ll long long
ll solve(ll idx, vector<ll>& dp, vector<int>& v) {
    if (idx == 0)
        return v[idx];
    if (idx < 0) {
        return 0;
    }
    if (dp[idx] != -1)
        return dp[idx];
    ll pick = v[idx] + solve(idx - 2, dp, v);
    ll notPick = solve(idx - 1, dp, v);
    return dp[idx] = max(pick, notPick);
}

long long int houseRobber(vector<int>& v) {
  // Write your code here.
    ll n = v.size();
    if (n == 1)
        return v[0];
    vector<ll> dp1(n + 1, -1), dp2(n + 1, -1);
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        if (i != 0)
            v1.push_back(v[i]);
        if (i != n - 1)
            v2.push_back(v[i]);
    }

    return max(solve(n - 2, dp1, v1), solve(n - 2, dp2, v2));
}