
// check prime number
#include <iostream>
using namespace std;

void solve()
{
    int n, i;
    // cout << "Enter a number: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "enter positive number" << endl;
        return;
    }

    if (n == 1)
        cout << "1 is neither prime nor composite number.";
    for (i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            cout << n << " is not a prime number.";
            return;
        }
    }
    cout << n << " is a prime number.";
}

int main()
{
    solve();

    return 0;
}
