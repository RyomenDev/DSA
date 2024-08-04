// https://www.naukri.com/code360/problems/minimum-insertions-to-make-palindrome_98529
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1
// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
// ! Minimum Insertions to Make String Palindrome

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

int minimumInsertions(string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    int res = lcs(s, t);
    return s.size() - res;
}
