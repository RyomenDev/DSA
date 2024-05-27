
#include <bits/stdc++.h>
using namespace std;

// recusion function to check if array is sorted
bool isSorted(int arr[], int n)
{
    if (n == 1 || n == 0)
        return true;
    if (arr[n - 1] < arr[n - 2])
        return false;

    return isSorted(arr, n - 1);
}

// binary search using recursion
int binarySearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid;
    if (high >= low)
        mid = low + (high - low) / 2;
    // If the element is present at the middle itself
    if (arr[mid] == x)
        return mid;

    // If element is smaller than mid, then it can only be present
    // in left subarray
    if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);

    // Else the element can only be present in right subarray
    else
        return binarySearch(arr, mid + 1, high, x);
}

// linear serach using recursion
// Finding sum of array using recusrion

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    cout << isSorted(arr, n) << endl;

    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;

    return 0;
}