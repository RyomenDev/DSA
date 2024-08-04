// https://www.naukri.com/code360/problem-details/longest-palindromic-subsequence_842787
// https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
// https://leetcode.com/problems/longest-palindromic-subsequence/

// ! Longest Palindromic Subsequence

#include <bits/stdc++.h> 
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
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
    string ans = "";
    int idx1 = n, idx2 = m;
    while (idx1 > 0 && idx2 > 0) {
        if (s[idx1 - 1] == t[idx2 - 1]) {
            ans = s[idx1 - 1] + ans;
            idx1--;
            idx2--;
        }
        else if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1])
            idx1--;
        else
            idx2--;
    }
    // cout << ans << endl;
    return ans.size();
}