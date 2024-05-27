// C. Product of Three Numbers
// https://codeforces.com/problemset/problem/1294/C

// check prime number
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    cout << "YES" << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
        cout << "NO" << endl;
    vector<int> v;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.emplace_back(i);
            n /= i;
        }
        if (v.size() == 2 && v[0] != n && v[1] != n)
        {
            if (n >= 1)
            {
                v.emplace_back(n);
                print(v);
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int tt;
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}

/*
6
64
32
97
2
12345
36
*/