// https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/0
// ! Partitions With Given Difference

/*
s1-s2=D
if(s1>s2) s1= totalSum - s2
totalSum-s1-s2=D
s2 = (totalSum-D)/2
*/

// const int MOD = 1e9 + 7;
// class Solution {
// public:
//     int countPartitions(int n, int d, vector<int>& arr) {
//         // Code here
//         int sum = accumulate(arr.begin(), arr.end(), 0);
//         int target = (d + sum) / 2;
//         if ((d + sum) % 2 != 0) return 0;
//         vector<int> dp(target + 1, 0);
//         dp[0] = 1;
//         for (int num : arr) 
//             for (int j = target; j >= num; --j) 
//                 dp[j] = (dp[j] + dp[j - num]) % MOD;
//         return dp[target];
//     }
// };

#include <bits/stdc++.h>
using namespace std;

// Define custom hash function for pairs
struct hash_pair {
    template <class T1, class T2> size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
int MOD = 1e9 + 7;

int solve(int idx, int k, unordered_map<pair<int, int>, int, hash_pair>& dp,
          vector<int>& arr) {
    if (idx == 0) {
        if (k == 0 && arr[idx] == 0)
            return 2;
        if (k == arr[idx] || k == 0)
            return 1;
        else
            return 0;
    }
    if (idx < 0 || k < 0)
        return 0;

    pair<int, int> key = {idx, k};
    if (dp.find(key) != dp.end())
        return dp[key];
      // pick
    int pick = solve(idx - 1, k - arr[idx], dp, arr) % MOD;
    // not pick
    int notPick = solve(idx - 1, k, dp, arr) % MOD;
    return dp[key] = (pick + notPick) % MOD;
}

int countPartitions(int n, int d, vector<int>& arr) {
  // Write your code here.
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int diff = totalSum - d;
    if (diff < 0 || diff & 1)
        return 0;
    int newTarget = diff / 2;

    unordered_map<pair<int, int>, int, hash_pair> dp;
    return solve(n - 1, newTarget, dp, arr);
}

// #include <bits/stdc++.h>
// using namespace std;

// int MOD = 1e9 + 7;

// struct hash_pair {
//     template <class T1, class T2> size_t operator()(const pair<T1, T2>& p) const {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };

// int countPartitions(int n, int d, vector<int>& num) {
//   // Write your code here.
//     int totalSum = accumulate(num.begin(), num.end(), 0);
//     int diff = totalSum - d;
//     if (diff < 0 || diff & 1)
//         return 0;
//     int newTarget = diff / 2;

//     int k = newTarget;
//     unordered_map<pair<int, int>, int, hash_pair> dp;
//     if (num[0] == 0)
//         dp[{0, 0}] = 2;
//     else
//         dp[{0, 0}] = 1;
//       // num[0]=0
//     if (num[0] != 0 && num[0] <= k)
//         dp[{0, num[0]}] = 1;

//     for (int idx = 1; idx < n; idx++) {
//         for (int sum = 0; sum <= k; sum++) {
//             pair<int, int> key = {idx - 1, sum - num[idx]};
//             int pick = (num[idx] <= sum) ? dp[key] % MOD : 0;
//             key = {idx - 1, sum};
//             int notPick = dp[key] % MOD;
//             key = {idx, sum};
//             dp[{idx, sum}] = (pick + notPick) % MOD;
//         }
//     }
//     return dp[{n - 1, k}];
// }