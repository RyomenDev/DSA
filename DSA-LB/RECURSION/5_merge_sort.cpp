#include <bits/stdc++.h>
using namespace std;

// O(nlogn)

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // creating temp arrays
    // int L[n1], R[n2];
    // dynamically
    int *L = new int[n1];
    int *R = new int[n2];

    // copying value to new array
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // comparing and merging
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])

            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // copying remaining elements
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete [](L);
    delete [](R);
}

// merge sort using recursion
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // left part
        mergeSort(arr, l, m);
        // right part
        mergeSort(arr, m + 1, r);
        // merge
        merge(arr, l, m, r);
    }
}

int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}