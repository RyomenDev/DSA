
#include <bits/stdc++.h>
using namespace std;

// sum of n numbers
// parameterised Way
void sum1(int n, int sum = 0)
{
    if (n == 0)
    // return sum;
    {
        cout << sum << endl;
        return;
    }
    return sum1(n - 1, sum+n);
}
// functional recursion
int sum2(int n)
{
    if (n == 0)
        return 0;

    return n + sum2(n - 1);
}
int main()
{
    // cout << sum1(5) << endl;
    sum1(5);
    cout << sum2(5) << endl;

    return 0;
}