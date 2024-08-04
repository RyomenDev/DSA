// https://www.naukri.com/code360/problems/can-you-make_4244510
// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

// https://leetcode.com/problems/delete-operation-for-two-strings/submissions/1289882855/   // ^ Delete Operation for Two Strings
// ! Minimum Insertions - Deletions to Convert String A to String B

int lcs(string s, string t) {
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

int canYouMake(string& s1, string& s2) {
  // Write your code here.
    int cnt = lcs(s1, s2);
    // Deletion = s1.size()-cnt;
    // Insertion = s2.size()-cnt;
    return s1.size() + s2.size() - 2 * cnt;
}