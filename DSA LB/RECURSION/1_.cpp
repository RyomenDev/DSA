
// Recursion : function calls itself

// Call Stack flow

// if recusive relation is in end : TAil Recursion
// if it is above Processing : Head Recursion

#include <iostream>
using namespace std;

// power n^e
int pOWER(int n, int e)
{
    // base case
    if (e == 0)
        return 1;
    return n * pOWER(n, e - 1);
}

// factorial
int fACTORIAL(int n)
{
    // base case
    if (n == 0 || n == 1)
        return 1;
    return n * fACTORIAL(n - 1);
}

// COUNTING
void cOUNT(int n)
{
    if (n == 0)
        return;
    // cOUNT(n - 1); // 1 2 3 4 5
    cout << n << " ";
    cOUNT(n - 1); // 5 4 3 2 1
}

int main()
{
    // to find 2^4
    cout << pOWER(2, 5) << endl;
    cout << fACTORIAL(5) << endl;
    cOUNT(5);
    return 0;
}