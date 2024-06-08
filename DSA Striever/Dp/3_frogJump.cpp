/*
https://www.naukri.com/code360/problems/frog-jump_3621012

*/
/*
! recursion to DP
^ Memoisation: look at the parameters which are changing.(generally index)
*/
#include <bits/stdc++.h>

int solve(int idx, vector<int> &dp, vector<int> &v)
{
  if (idx == 0)
    return 0;
  if (dp[idx] != -1)
    return dp[idx];
  int left = solve(idx - 1, dp, v) + abs(v[idx] - v[idx - 1]);
  int right = INT_MAX;
  if (idx > 1)
    right = solve(idx - 2, dp, v) + abs(v[idx] - v[idx - 2]);
  return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
  // Write your code here.
  // vector<int> dp(n + 1, -1);
  // return solve(n-1, dp, heights);

  // dp[0] = 0;
  // for (int i = 1; i < n; i++)
  // {
  //   int fs, ss = INT_MAX;
  //   fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
  //   if (i > 1)
  //     ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
  //   dp[i] = min(fs, ss);
  // }
  // return dp[n-1];
  
  int prev = 0, prevPrev = 0, ans = 0;
  for (int i = 1; i < n; i++)
  {
    int fs, ss = INT_MAX;
    fs = prev + abs(heights[i] - heights[i - 1]);
    // fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    if (i > 1)
      ss = prevPrev + abs(heights[i] - heights[i - 2]);
    // ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    ans = min(fs, ss);
    // dp[i] = min(fs, ss);
    prevPrev=prev;
    prev=ans;
  }
  return ans;
}