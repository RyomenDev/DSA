// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// ! Minimum Platforms

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        multiset<pair<int, char>> order; // sorted order
        for (int i = 0; i < n; i++) {
            order.insert({arr[i], 'a'}); // arrival
            order.insert({dep[i], 'd'}); // departure
        }

        int result = 0;
        int platforms_needed = 0;

        // Iterate through the multiset
        for (auto it : order) {
            if (it.second == 'a') // If it's an arrival
                platforms_needed++;
            else // If it's a departure
                platforms_needed--;
            result = max(platforms_needed, result);
        }

        return result; // Return the minimum number of

    }
};



//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
// } Driver Code Ends