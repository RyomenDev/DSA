// https://www.naukri.com/code360/problems/ninja-s-training_3621003
//! Ninja's Training

#include <bits/stdc++.h>

int solve(int idx, int lastTask, vector<vector<int>>& dp,
          vector<vector<int>>& v) {
    if (idx == 0) {
        int max_points = 0;
        for (int task = 0; task < 3; task++)
            if (task != lastTask)
                max_points = max(max_points, v[0][task]);
        return max_points;
    }
    if (dp[idx][lastTask] != -1)
        return dp[idx][lastTask];
    int max_points = 0;
    for (int task = 0; task < 3; task++) {
        if (task != lastTask) {
            int currPoint = v[idx][task] + solve(idx - 1, task, dp, v);
            max_points = max(max_points, currPoint);
        }
    }
    return dp[idx][lastTask] = max_points;
}

int ninjaTraining(int n, vector<vector<int>>& v) {
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    // return solve(n - 1, 3, dp, v); // Starting with last_task = 3 (none of the tasks)
    // vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    //   int ans = INT_MIN;
    //   for (int task = 0; task < 3; task++) {
    //     ans = max(ans, solve(n - 1, task, dp, v));
    //   }
    //   return ans;

    // dp[0][0] = v[0][0];
    // dp[0][1] = v[0][1];
    // dp[0][2] = v[0][2];
    // // Fill the DP table for subsequent days
    // for (int day = 1; day < n; ++day) {
    //   dp[day][0] = v[day][0] + max(dp[day - 1][1], dp[day - 1][2]);
    //   dp[day][1] = v[day][1] + max(dp[day - 1][0], dp[day - 1][2]);
    //   dp[day][2] = v[day][2] + max(dp[day - 1][0], dp[day - 1][1]);
    //   dp[day][3] = max(dp[day][0], max(dp[day][1], dp[day][2]));
    // }
    // return dp[n - 1][3];

    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(v[0][0], max(v[0][1], v[0][2]));
    // Fill the DP table for subsequent days
    for (int day = 1; day < n; ++day) {
        for (int last = 0;last < 4;last++) {
            dp[day][last] = 0;
            for (int task = 0;task < 3;task++) {
                if (task != last) {
                    int point = v[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}