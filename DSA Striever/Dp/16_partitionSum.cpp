// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
// ! Array partition with minimum difference

#define vvi vector<vector<int>>
#define vi vector<int>

void subsetSumUtil(int ind, int target, int& ans, int total, vi& arr, vvi& dp) {
    if (ind < 0) {
        ans = min(ans, abs((total - target) - target));
        return;
    }
    if (dp[ind][target] != -1)
        return;
    dp[ind][target] = 1;
    // notTaken
    subsetSumUtil(ind - 1, target, ans, total, arr, dp);
    if (arr[ind] <= target)
        subsetSumUtil(ind - 1, target - arr[ind], ans, total, arr, dp);
      // taken
}

int minSubsetSumDifference(vector<int>& arr, int n) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vvi dp(n, vi(sum + 1, -1));

    // int ans = INT_MAX;
    // subsetSumUtil(n - 1, sum, ans, sum, arr, dp);

    // return ans;


    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    for (int idx = 1; idx < n; idx++) {
        for (int tgt = 1; tgt <= sum; tgt++) {
            bool pick = (tgt >= arr[idx]) ? dp[idx - 1][tgt - arr[idx]] : 0;
            // not pick
            bool notPick = dp[idx - 1][tgt];
            dp[idx][tgt] = (pick || notPick);
        }
    }

    int ans = INT_MAX;
    // Find the minimum subset sum difference
    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n - 1][i] == true) {
            int s1 = i, s2 = sum - i;
            ans = min(ans, abs(s1 - s2));
        }
    }

    return ans;
}