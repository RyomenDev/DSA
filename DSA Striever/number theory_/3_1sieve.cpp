
// https://www.spoj.com/problems/TDKPRIME/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// const ll N = 1e8;
const ll N = 86028122; // 86028121
bool isPrime[N + 1];

void sieveOfEratosthenes()
{
    for (ll i = 2; i <= N; i++)
        isPrime[i] = true;

    for (ll p = 2; p * p <= N; p++)
        if (isPrime[p])
            for (ll i = p * p; i <= N; i += p)
                isPrime[i] = false;
}

vector<ll> generatePrimes()
{
    sieveOfEratosthenes();
    vector<ll> prime;
    for (ll p = 2; p <= N; p++)
        if (isPrime[p])
            prime.push_back(p);

    return prime;
}
// vector<bool> generatePrimes()
// {
//     sieveOfEratosthenes();
//     vector<bool> prime;
//     int size = 1, limit = 5000000;
//     int count = 0;

//     for (ll p = 2; p <= N; p++)
//         if (isPrime[p])
//         {
//             prime.push_back(p);
//             count++;
//             if (count == limit)
//             {
//                 size = p;
//                 break;
//             }
//         }
//     cout << count << " " << size << endl;

//     return prime;
// }

void solve(vector<ll> prime)
{
    ll n;
    cin >> n;
    // vector<bool> prime = generatePrimes();
    cout << prime[n - 1] << endl;
}

int main()
{
    int tt;
    cin >> tt;
    vector<ll> prime = generatePrimes();
    while (tt--)
        solve(prime);

    return 0;
}
/*
Input:
7
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863
*/