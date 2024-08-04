#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"

string solve(int even, int odd) {
    if (odd == 0)
        return "Alice";
    else {
        int tmp = ((odd + 1) / 2) % 2;
        if (tmp == 0)
            return "Alice";
        else
            return "Bob";
    }
    return "";
}

void Vatsh()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp & 1)odd++;
        else even++;
    }
    cout << solve(even, odd) << endl;

}

int32_t main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}