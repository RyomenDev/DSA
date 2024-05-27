
// how many number in range (1-1e6) have minimum prime factor n

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 10;
vector<int> isPrime(N, 1);
// map<int, int> prime;

void sieveOfEratosthenes()
{
    // for (ll i = 2; i <= N; i++)
    // {
    //     isPrime[2]++;
    //     isPrime[i] = 0;
    // }

    for (ll p = 2; p * p <= N; p++)
    {
        if (isPrime[p])
        {
            for (ll i = p * p; i <= N; i += p)
            {
                if (isPrime[i] == 1)
                {
                    isPrime[p]++;
                    isPrime[i] = 0;
                }
            }
        }
    }
}

// void generatePrimes()
// {
//     sieveOfEratosthenes();
//     prime[1] = 1;
//     for (ll p = 2; p <= N; p++)
//         prime[isPrime[p]]++;
// }

void solve()
{
    ll n;
    cin >> n;
    cout << isPrime[n] << endl;
}

int main()
{
    int tt;
    cin >> tt;
    sieveOfEratosthenes();
    while (tt--)
        solve();

    return 0;
}
