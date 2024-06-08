// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// ! Bellman Ford Algorithm
// ^ sortest Path  works for -ve weight but not in -ve cycle
// ^ helps to detect -ve cycles

// % in undirected graph represent in the form of directed graph.

/*
/ relax all edges v-1 times sequentially. (v is no. of nodes)
/ why (v-1) ? at each iteration 1 edge is relaxed (atleast).
* relax - if u have distance array and (distance to reach u and edge weight required < distance[v] )
*   then  update distance[v]=distance[u]+wt

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) // O(v*e)
    {
        // Code here
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (distance[u] != 1e8 && distance[u] + wt < distance[v])
                {
                    distance[v] = distance[u] + wt;
                }
            }
        }
        // check for negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (distance[u] != 1e8 && distance[u] + wt < distance[v])
            {
                return {-1};
            }
        }
        return distance;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends