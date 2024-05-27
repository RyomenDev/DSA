// xor of numbers in a given range 1 to n
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    if (n % 4 == 1)
        ans = 1;
    else if (n % 4 == 2)
        ans = n + 1;
    else if (n % 4 == 3)
        ans = 0;
    else if (n % 4 == 0)
        ans = n;
    cout << ans << endl;
    return 0;
}

// range L to R
// convert to 1 to n
// func(L-1)^func(R)

#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else if (n % 4 == 0)
        return n;
}

int main()
{
    int l, r;
    cin >> l >> r;
    // return func(L-1)^func(R);
    int ans = 0;
    if ((r - l + 1) % 4 == 1)
        ans = 1;
    else if ((r - l + 1) % 4 == 2)
        ans = r + 1;
    else if ((r - l + 1) % 4 == 3)
        ans = 0;
    else if ((r - l + 1) % 4 == 0)
        ans = r;
    cout << ans << endl;
    return 0;
}