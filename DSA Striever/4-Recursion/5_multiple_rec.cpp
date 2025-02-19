// multiple recursion calls

#include <bits/stdc++.h>
using namespace std;

// fibonacci series
// time complexity - O(2^n)
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    int last = fib(n - 1);
    // int secondLast = fib(n - 2);
    // int ans = last + secondLast;
    // return ans;
    return fib(n-1)+fib(n-2);
}

int main()
{
    cout << fib(10) << endl;
    return 0;
}