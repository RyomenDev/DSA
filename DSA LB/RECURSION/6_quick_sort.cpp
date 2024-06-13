
// quick sort using recursion

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    // find pivot element such that element smaller than pivot are on the left and elements greater than pivot are on the right
    int pivot = arr[low];
    int count = 0;
    for (int i = low + 1; i <= high; i++)
        if (arr[i] <= pivot)
            count++;

    // Giving pivot element its correct position
    int pivotIndex = low + count;
    swap(arr[pivotIndex], arr[low]);

    // LEFT PART & RIGHT PART
    int i = low, j = high;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int low, int high)
{
    // base case
    if (low >= high)
        return;

    // partition
    int p = partition(arr, low, high);

    // recursive call
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}