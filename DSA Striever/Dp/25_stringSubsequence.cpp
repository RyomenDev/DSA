// https://www.naukri.com/code360/problems/longest-common-subsequence_624879
// https://leetcode.com/problems/longest-common-subsequence/
// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// Longest Common Subsequence DP on Strings

/*
^ subsequence : contiguous | non -contiguous - maintain relative order
^ subArray : contiguous - maintain relative order
^ subset : may or may not contiguous - do not maintain relative order
^ substring :  contiguous - maintain relative order
*/
/*
^ EXPRESS (idx1 ,idx2)
^ Explore possibility on that indexes
^ take the best among them
*/

#include <vector>
int solve(int idx1, int idx2, string s, string t, vector<vector<int>>& dp) {
    if (idx1 < 0 || idx2 < 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];
    if (s[idx1] == t[idx2])
        return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s, t, dp);
    return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, s, t, dp),
                                solve(idx1, idx2 - 1, s, t, dp));
}

int lcs(string s, string t) {
  // Write your code here
  //   int n = s.size(), m = t.size();
  //   vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  //   return solve(n - 1, m - 1, s, t, dp);

    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int idx1 = 1; idx1 <= n; idx1++) {
        for (int idx2 = 1; idx2 <= m; idx2++) {
            if (s[idx1 - 1] == t[idx2 - 1])
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            else
                dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
        }
    }
    return dp[n][m];
}