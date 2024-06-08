// ! Prim's Algo
// % https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
/*
 */
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pr pair<int, pair<int, int>>

class Solution
{
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    vector<bool> inMST(V, false);

    for (auto it : adj[0])
      pq.push({it[1], {0, it[0]}});

    int mstCost = 0;
    int edgesInMST = 0;

    // Continue until we include V-1 edges in the MST
    while (!pq.empty() && edgesInMST < V - 1)
    {
      auto top = pq.top();
      pq.pop();
      int weight = top.first;
      int u = top.second.first;
      int v = top.second.second;

      if (inMST[v])
        continue;
      // Include this edge in MST
      inMST[v] = true;
      mstCost += weight;
      edgesInMST++;

      // Add all edges from the new vertex
      for (auto it : adj[v])
        if (!inMST[it[0]])
          pq.push({it[1], {v, it[0]}});
    }

    return mstCost;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
      int u, v, w;
      cin >> u >> v >> w;
      vector<int> t1, t2;
      t1.push_back(v);
      t1.push_back(w);
      adj[u].push_back(t1);
      t2.push_back(u);
      t2.push_back(w);
      adj[v].push_back(t2);
    }

    Solution obj;
    cout << obj.spanningTree(V, adj) << "\n";
  }

  return 0;
}

// } Driver Code Ends