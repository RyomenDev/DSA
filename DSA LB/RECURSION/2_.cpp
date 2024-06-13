#include <bits/stdc++.h>
using namespace std;

// destination travel home
int reachHome(int src, int dest)
{
    if (src == dest)
        return 0;
    return 1 + reachHome(src + 1, dest);
}

// fabonacci
int fabonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fabonacci(n - 1) + fabonacci(n - 2);
}

// climbing starirs
int climb(int n)
{
    // 1 or 2 step at atime
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1 || n == 2)
        return n;
    return climb(n - 1) + climb(n - 2);
}

// find digits
void digits(int n)
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    digits(n / 10);
    cout << digit << " ";
    return;
}

int main()
{

    cout << reachHome(1, 10) << endl;
    cout << fabonacci(6) << endl;
    cout << climb(6) << endl;
    digits(12345);

    return 0;
}

// 36:40