// https://www.naukri.com/code360/problems/longest-common-substring_1235207
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// !  Longest Common Substring _ DP on Strings 🔥

// ^ substring :  contiguous - maintain relative order

int lcs(string& s, string& t) {
  // Write your code here.
    int n = s.size(), m = t.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int idx1 = 1; idx1 <= n; idx1++) {
        for (int idx2 = 1; idx2 <= m; idx2++) {
            if (s[idx1 - 1] == t[idx2 - 1])
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            else
                dp[idx1][idx2] = 0;
            ans = max(ans, dp[idx1][idx2]);
        }
    }
    return ans;
}