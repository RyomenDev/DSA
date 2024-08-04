// https://www.naukri.com/code360/problems/shortest-supersequence_4244493
// https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// https://leetcode.com/problems/shortest-common-supersequence/submissions/1291950771/
// ! Shortest Common SuperSequence - DP on Strings

#include <bits/stdc++.h>

string shortestSupersequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //   cout << m + n - dp[n][m] << " ";
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) { // up
            ans += s[i - 1];
            i--;
        }
        else { // left
            ans += t[j - 1];
            j--;
        }
    }
    while (i > 0) {
        ans += s[i - 1];
        i--;
    }
    while (j > 0) {
        ans += t[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
  //   cout << ans << " ";
    return ans;
}