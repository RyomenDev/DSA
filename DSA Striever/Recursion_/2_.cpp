//  Recursion using backtracking

#include <bits/stdc++.h>
using namespace std;

// printing 1 to N using recursion with backtracking
void print(int n)
{
    if (n < 1)
        return;
    print(n-1);
    cout << n << " ";
}

int main()
{
    print(5);
    return 0;
}
