//  Sieve of Eratosthenes
/*
The Sieve of Eratosthenes is an efficient algorithm for finding all prime numbers up to a specified integer n.
It works by iteratively marking the multiples of each prime number starting from 2 as composite (not prime). At the end of the process, the unmarked numbers are prime.
*/

#include <iostream>
#include <vector>

using namespace std;

// N=1e6  max
// O(n log(log n))
void sieveOfEratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true); // Initialize all numbers as prime

    for (int p = 2; p * p <= n; p++)
    {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p] == true)
        {
            // Mark all multiples of p as composite
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    // Print prime numbers
    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
        {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Prime numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);

    return 0;
}
