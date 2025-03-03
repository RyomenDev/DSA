// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int ans = 0;
    void merge(vector<int>& arr, int left, int mid, int right) {
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && arr[i] > arr[j])
                j++;
            ans += (j - (mid + 1));
        }
        // sort(arr.begin()+left,arr.begin()+right+1);
        int n1 = mid - left + 1, n2 = right - mid;
        vector<int>L, R;
        for (int i = 0; i < n1; i++)
            L.push_back(arr[left + i]);
        for (int i = 0; i < n2; i++)
            R.push_back(arr[mid + i + 1]);
        int i = 0, k = left;
        j = 0;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }
        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
public:
    int inversionCount(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
        // for(auto i : arr)
        //     cout<<i<<' ';
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends