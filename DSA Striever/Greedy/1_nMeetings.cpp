// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// ! N meetings in one room

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
//Function to find the maximum number of meetings that can
//be performed in a meeting room.

    int maxMeetings(int start[], int end[], int n)
    {
    // function to sort start according end time
        vector<pair<int, int>>v;
        for (int i = 0; i < n; i++)
            v.push_back({end[i],start[i]});
        sort(v.begin(), v.end());// nlogn
        /*
        for(int i=0;i<n;i++){
            start[i]=v[i].second;
            end[i]=v[i].first;
        }
        int count=1;// first task will complete irrespective
        int prevEnd=end[0];
        for(int i=1;i<n;i++){
            if(start[i]>prevEnd){
                count++;
                prevEnd=end[i];
                // cout<<start[i]<<" ";
            }
            else{
                continue;
            }
        }
        */
        int count = 1;
        int prevEnd = v[0].first;
        for (int i = 1; i < n; i++) {
            if (v[i].second > prevEnd) {
                count++;
                prevEnd = v[i].first;
            }
            else
                continue;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
