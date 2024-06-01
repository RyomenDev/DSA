// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// https://leetcode.com/problems/detect-cycles-in-2d-grid/submissions/1272158791/
// Detect cycle in an undirected graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int vertex, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q; // {current_node, parent_node}
        q.push({vertex, -1});
        vis[vertex] = true;

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int i = 0; i < adj[node].size(); ++i)
            {
                int next = adj[node][i];
                if (!vis[next])
                {
                    vis[next] = true;
                    q.push({next, node});
                }
                else if (next != parent)
                {
                    // If the next node is visited and not the parent of the current node,
                    // it means there is a cycle.
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (bfs(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends