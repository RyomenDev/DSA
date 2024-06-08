#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"

int recursive(int i, int K, vector<int> dp, vector<int> h)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int cost = LLONG_MAX;
    for (int j = max(0, i - K); j < i; ++j)
    {
        cost = min(cost, recursive(j, K, dp, h) + abs(h[i] - h[j]));
    }

    dp[i] = cost; // Cache the result
    return cost;
}

void iterative(int N, int K, vector<int> dp, vector<int> h)
{
    dp[0] = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j <= i + K && j < N; ++j)
        {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
}
void Vatsh()
{
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; ++i)
        cin >> h[i];

    vector<int> dp(N, LLONG_MAX);
    // iterative(N, K, dp, h);
    recursive(N, K, dp, h);
    cout << dp[N - 1] << endl;
}

int32_t main()
{
    Vatsh();

    return 0;
}
