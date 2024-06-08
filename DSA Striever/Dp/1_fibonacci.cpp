/*
^ memoization -> top down dynamic programming
^ tabulation -> bottom up dynamic programming : base case to required answer
*/

// ! fibonacci number

/*
@ memoization
    / tend to  store the value of sub-problem in some map/table
    / 1 parameter : 1D array
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"

int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

void Vatsh()
{
    // Your logic goes here
    int n;
    cin >> n;
    // int dp[n + 1];
    // memset(dp, -1, sizeof dp);

    // @ memoization
    // vector<int> dp(n + 1, -1);
    // cout << fib(n, dp) << endl;

    // @ tabulation
    // vector<int> dp(n + 1, -1);

    // dp[0]=0, dp[1]=1;
    // for(int i=2;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n]<<endl;

    // % space optimization
    int prevPrev = 0, prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;
    }
    cout << prev << endl;
}

int32_t main()
{

    int tt = 1;
    // cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}