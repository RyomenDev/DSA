// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"


int solve(int idx, vector<int>& dp, vector<int>& v, int k) {
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int currMinSteps = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (idx - i >= 0) {
            int jumpEnergy = solve(idx - i, dp, v, k) + abs(v[idx] - v[idx - i]);
            currMinSteps = min(currMinSteps, jumpEnergy);
        }
    }
    return dp[idx] = currMinSteps;
}


int minJumpCost(vector<int>& v, int k) {
    int n = v.size();
    vector<int> dp(n + 1, -1);
    // return solve(n - 1, dp, v, k);
    dp[0] = 0;
    for (int idx = 1;idx < n;idx++) {
        int currMinSteps = INT_MAX;
        for (int i = 1;i <= k;i++) {
            if (idx - i >= 0) {
                int jumpEnergy = dp[idx - i] + abs(v[idx] - v[idx - i]);
                currMinSteps = min(currMinSteps, jumpEnergy);
            }
        }
        dp[idx] = currMinSteps;
    }
    return dp[n - 1];
}


void Vatsh()
{
    // Your logic goes here
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0;i < n;i++)
        cin >> v[i];
    cout << minJumpCost(v, k) << endl;

}

int32_t main()
{

    int tt = 1;
    //cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}