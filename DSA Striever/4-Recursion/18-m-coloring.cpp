// https://leetcode.com/problems/flower-planting-with-no-adjacent/description/
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool isSafe(int node, int currColor, vector<int>& color, vector<vector<int>>& adj) {
        for (auto i : adj[node])
            if (color[i] == currColor)
                return false;
        return true;
    }
    bool solve(int node, vector<int>& color, vector<vector<int>>& adj, int m, int V) {
        if (node == V)
            return true;
        for (int i = 1; i <= m; i++) {
            if (isSafe(node, i, color, adj)) {
                color[node] = i;
                if (solve(node + 1, color, adj, m, V))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
public:
    bool graphColoring(int V, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>>adj(V);
        for (auto edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        vector<int>color(V, 0);
        return solve(0, color, adj, m, V);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
            << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends