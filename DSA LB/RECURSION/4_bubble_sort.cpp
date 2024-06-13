
// recursion with strings
#include <bits/stdc++.h>
using namespace std;

// print all the substrings
void printSubStirng(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    // take
    printSubStirng(ros, ans + ch);
    // do not take
    printSubStirng(ros, ans);
}

// reverse the string
// void reverseString(string &s)
// {
//     if (s.length() == 0)
//     {
//         return;
//     }
//     char ch = s[0];
//     string ros = s.substr(1);
//     reverseString(ros);
//     cout << ch;
//     return;
// }

// reversing
void reverseString(string &s, int i, int j)
{
    if (i > j)
        return;
    swap(s[i], s[j]);
    i++;
    j--;
    reverseString(s, i, j);
}

// checkPalindrome using recursion
bool checkPalindrome(string s, int i, int j)
{
    if (i > j)
        return true;
    if (s[i] != s[j])
        return false;
    return checkPalindrome(s, i + 1, j - 1);
}

// finding power
int power(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(x, n / 2) * power(x, n / 2);
    else
        return x * power(x, n / 2) * power(x, n / 2);
}

// bubble sort using recusrion
void bubbleSort(int arr[], int n)
{
    if (n == 1 || n == 0)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubbleSort(arr, n - 1);
}

int main()
{
    string s = "abcd";
    printSubStirng(s, "");
    cout << endl;

    reverseString(s, 0, s.length() - 1);
    cout << s << endl;

    string str = "abbccbba";
    cout << checkPalindrome(str, 0, str.length() - 1) << endl;

    cout << power(4, 3) << endl;

    int arr[] = {4, 2, 6, 5, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
