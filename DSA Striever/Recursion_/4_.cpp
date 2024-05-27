#include <bits/stdc++.h>
using namespace std;

// reverse an array
void reverse(int arr[], int low, int high)
{
    if (low > high)
        return;
    swap(arr[low], arr[high]);
    reverse(arr, low + 1, high - 1);
}

// check if palindrome
bool palindrome(string s, int low, int high)
{
    if (low >= high)
        return true;
    if (s[low] != s[high])
        return false;
    return palindrome(s, low + 1, high - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    string s = "madam";
    cout << palindrome(s, 0, s.length() - 1) << endl;

    return 0;
}